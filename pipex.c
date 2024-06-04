/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:23 by itykhono          #+#    #+#             */
/*   Updated: 2024/06/04 15:18:10 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

static int	ft_save_to_output_fd(char *filename, char *result) {
	int	output_fd;
	int	len;

    output_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (output_fd < 0) {
		ft_printf("%d", strerror(errno));
        return (-210);
    }
	if (!result)
		len = 0;
	else
		len = ft_strlen(result);
	if (write(output_fd, result, len) < 0);
	{
		ft_printf("%s", strerror(errno));
		return(-211);
	}
	close(output_fd);
	return (0);
}

static char	*read_input(int inputfd) {
	char	*result;
	
	result = get_next_line(inputfd);
	close(inputfd);
	return (result);
}

static int	read_input_and_write_into_pipe(int inputfd, int pipe_fd) {
	char	*result;
	int		len;

	result = get_next_line(inputfd);
	if (!result)
		len = 0;
	else
		len = ft_strlen(result);
	
    if (write(pipe_fd, result, len) == -1)
	{
		ft_printf("%s", strerror(errno));
		return (-202);
	}
	close(inputfd);
	close(pipe_fd);
	free(result);
	return(0);
}

static void ft_close_all_pipes(int all_pipes[][2], int pipes_amount, int *exeption_pipe)
{
	int	i;
	i = 0;
	while (i < pipes_amount)
	{
		if(all_pipes[i][0] && all_pipes[i][0] != *exeption_pipe)
		{
			close(all_pipes[i][0]);
		}
		if(all_pipes[i][1] && all_pipes[i][1] != *exeption_pipe)
		{
			close(all_pipes[i][1]);
		}
		i++;
	}
}

static int ft_create_pipes(int pipe_amount, int created_pipes[][2]) {
    int i;
    i = 0;
    while (i < pipe_amount) {
        if (pipe(created_pipes[i]) == -1) {
            while (i >= 0) {
                close(created_pipes[i][1]);
                close(created_pipes[i][0]);
                i--;
            }
            ft_printf("%s", strerror(errno));
            return -242;
        }
        i++;
    }
    // ft_printf("pipe_created_counter: %d\n", i);
    return (200);
}

char *ft_exe_cmd(char **argvs, int infile_fd, int cmds) {
    char **exe_arguments;
    int pipes_fd[cmds + 1][2];
    int child_fd;
    int pid;
    char *result_str;
	int cmd_index;

	cmd_index = 0;
    // Create all Pipes
    if (ft_create_pipes(cmds + 1, pipes_fd) == -242) {
        ft_printf("%s", strerror(errno));
        return (NULL);
    }

	if (read_input_and_write_into_pipe(infile_fd, pipes_fd[0][1]) < 0)
		return (NULL);
	// ft_printf("infile contains: %d \n", input_str);
    // write(pipes_fd[0][1], input_str, ft_strlen(input_str));
	pid = 2;
	while (cmd_index < cmds)
	{
		if (pid > 0)
		{
			pid = fork();
		}
		if (pid < 0)
		{
			ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
			ft_printf("%s", strerror(errno));
			return (NULL);	
		}
		if (pid == 0) {
		// ONLY CHILD ACCESS
			if (dup2(pipes_fd[cmd_index][0], STDIN_FILENO) < 0) {
				ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
				ft_printf("dup2 failed for stdin in child: %s\n", strerror(errno));
				return (NULL);
			}
			
			if (dup2(pipes_fd[cmd_index + 1][1], STDOUT_FILENO) < 0) {
				ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
				ft_printf("dup2 failed for stdout in child: %s\n", strerror(errno));
				return (NULL);
			}
			ft_close_all_pipes(pipes_fd, cmds + 1, &(pipes_fd[0][1]));
			// Execute CMD
			exe_arguments = ft_split(argvs[cmd_index + 2], ' '); //prog name + infile 
			if (!exe_arguments) {
				// ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
				exit(-333);
			}
			char *path_cmd = ft_strjoin("/bin/", exe_arguments[0]);
			if (!path_cmd) {
				// ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
				exit(-333);
			}
			// ft_printf("cmd_path = %s\n", path_cmd);
			execve(path_cmd, exe_arguments, NULL);
		}
		cmd_index++;
		// ft_printf("cmd_index = %d\n", cmd_index);
	}
    // Close all pipes in the parent process
	ft_close_all_pipes(pipes_fd, cmds + 1, &(pipes_fd[cmds][0]));
    // Wait for children to complete
    wait(NULL);

	result_str = read_input(pipes_fd[cmds][0]);
    close(pipes_fd[cmds][0]);
    return result_str;
}

int main(int argc, char **argv)
{
	int inputfd;
	int	output_fd;
	int return_status;

	return_status = 0;
	inputfd = open(argv[1], O_RDONLY);
	if (inputfd < 0)
	{
		ft_printf("%s: %s", strerror(errno), argv[1]);
		close(inputfd);
		return (1);		
	}
	int cmds = argc - 3;
	char *tempRes = ft_exe_cmd(argv, inputfd, cmds);
	if (ft_save_to_output_fd(argv[argc -1], tempRes) < 0)
		return_status = 0;
	free(tempRes);
	return (return_status);
}

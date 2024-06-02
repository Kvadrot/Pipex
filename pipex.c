/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:23 by itykhono          #+#    #+#             */
/*   Updated: 2024/06/02 14:24:42 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int ft_get_outfile_fd(char *filename) {
	int fd;
	fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	return (fd);
}


char *read_input(int inputfd) {
	char	*result;
	
	result = get_next_line(inputfd);
	// ft_printf("input file: %s\n", result);
	close(inputfd);
	return (result);
}

static void ft_close_all_pipes(int all_pipes[][2], int pipes_amount)
{
	int	i;
	i = 0;
	while (i < pipes_amount)
	{
		if(all_pipes[i][0])
		{
			close(all_pipes[i][0]);
		}
		if(all_pipes[i][1])
		{
			close(all_pipes[i][1]);
		}
		i++;
	}
}

int ft_create_pipes(int pipe_amount, int created_pipes[][2]) {
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

	char *input_str;
	input_str = read_input(infile_fd);
    write(pipes_fd[0][1], input_str, ft_strlen(input_str));
    close(pipes_fd[0][1]); // Close the write end of the first pipe
	free(input_str);
	
    // // DEBUG PRINT
    // char temp[25];
    // read(pipes_fd[0][0], temp, 25);
    // ft_printf("String was written to the pipes_fd[0][0]: %s\n", temp);
    // ft_printf("main closed: pipes_fd[0][1]\n");
    // //DEBUG PRINT

	pid = 2;
	while (cmd_index < cmds)
	{
		if (pid > 0)
		{
			pid = fork();
		}
		if (pid < 0)
		{
			ft_close_all_pipes(pipes_fd, cmds + 1);
			ft_printf("%s", strerror(errno));
			return (NULL);	
		}

		if (pid == 0) {
		// ONLY CHILD ACCESS
			if (dup2(pipes_fd[cmd_index][0], STDIN_FILENO) < 0) {
				ft_close_all_pipes(pipes_fd, cmds + 1);
				ft_printf("dup2 failed for stdin in child: %s\n", strerror(errno));
				return (NULL);
			}
			
			if (dup2(pipes_fd[cmd_index + 1][1], STDOUT_FILENO) < 0) {
				ft_close_all_pipes(pipes_fd, cmds + 1);
				ft_printf("dup2 failed for stdout in child: %s\n", strerror(errno));
				return (NULL);
			}
			close(pipes_fd[0][0]);
			close(pipes_fd[1][1]);

			// Close all other pipes
			close(pipes_fd[1][0]);
			close(pipes_fd[2][1]);
			close(pipes_fd[2][0]);

			// Execute CMD
			exe_arguments = ft_split(argvs[cmd_index + 2], ' '); //prog name + infile 
			if (!exe_arguments) {
				ft_close_all_pipes(pipes_fd, cmds + 1);
				exit(-333);
			}
			char *path_cmd = ft_strjoin("/bin/", exe_arguments[0]);
			if (!path_cmd) {
				ft_close_all_pipes(pipes_fd, cmds + 1);
				exit(-333);
			}
			execve(path_cmd, exe_arguments, NULL);
		}
		cmd_index++;
	}
    // Close all pipes in the parent process
    close(pipes_fd[0][0]);
    close(pipes_fd[1][0]);
    close(pipes_fd[1][1]);
    close(pipes_fd[2][1]);

    // Wait for children to complete
    wait(NULL);

    //DEBUG PRINT
    // char temp2[30];
    // read(pipes_fd[2][0], temp2, 30);
    // ft_printf("pipes_fd[2][0] Contains: %s\n", temp2);
    //DEBUG PRINT
	result_str = read_input(pipes_fd[2][0]);
    close(pipes_fd[2][0]);
    return result_str;
}

// char *ft_exe_cmd(char **argvs, int infile_fd, int cmds) {
//     char **exe_arguments;
//     int pipes_fd[cmds + 1][2];
//     int child_fd;
//     int grandchild;
//     char *result_str;

//     // Create all Pipes
//     if (ft_create_pipes(cmds + 1, pipes_fd) == -242) {
//         ft_printf("%s", strerror(errno));
//         return (NULL);
//     }

// 	char *infile_str = read_input(infile_fd);
//     write(pipes_fd[0][1], infile_str, ft_strlen(infile_str));
// 	free(infile_str);
//     close(pipes_fd[0][1]); // Close the write end of the first pipe

//     if ((child_fd = fork()) < 0) {
//         ft_close_all_pipes(pipes_fd, cmds + 1);
//         ft_printf("%s", strerror(errno));
//         return (NULL);
//     }

//     // ONLY CHILD ACCESS
//     if (child_fd == 0) {
//         if (dup2(pipes_fd[0][0], STDIN_FILENO) < 0) {
//             ft_close_all_pipes(pipes_fd, cmds + 1);
//             ft_printf("dup2 failed for stdin in child: %s\n", strerror(errno));
//             return (NULL);
//         }
        
//         if (dup2(pipes_fd[1][1], STDOUT_FILENO) < 0) {
//             ft_close_all_pipes(pipes_fd, cmds + 1);
//             ft_printf("dup2 failed for stdout in child: %s\n", strerror(errno));
//             return (NULL);
//         }
		
// 		close(pipes_fd[0][0]);
//         close(pipes_fd[1][1]);

//         // Close all other pipes
//         close(pipes_fd[1][0]);
//         close(pipes_fd[2][1]);
//         close(pipes_fd[2][0]);

//         // Execute CMD
//         exe_arguments = ft_split(argvs[2], ' ');
//         if (!exe_arguments) {
//             ft_close_all_pipes(pipes_fd, cmds + 1);
//             exit(-333);
//         }
//         char *path_cmd = ft_strjoin("/bin/", exe_arguments[0]);
//         if (!path_cmd) {
//             ft_close_all_pipes(pipes_fd, cmds + 1);
//             exit(-333);
//         }
//         execve(path_cmd, exe_arguments, NULL);
//     }

//     if ((grandchild = fork()) < 0) {
//         ft_close_all_pipes(pipes_fd, cmds + 1);
//         ft_printf("%s", strerror(errno));
//         return (NULL);
//     }

//     if (grandchild == 0) {
//         if (dup2(pipes_fd[1][0], STDIN_FILENO) < 0) {
//             ft_close_all_pipes(pipes_fd, cmds + 1);
//             ft_printf("dup2 failed for stdin in grandchild: %s\n", strerror(errno));
//             exit(-434);
//         }
//         close(pipes_fd[1][0]);

//         if (dup2(pipes_fd[2][1], STDOUT_FILENO) < 0) {
//             ft_close_all_pipes(pipes_fd, cmds + 1);
//             ft_printf("dup2 failed for stdout in grandchild: %s\n", strerror(errno));
//             exit(-435);
//         }
//         close(pipes_fd[2][1]);

//         // Close all other pipes
//         close(pipes_fd[1][1]);
//         close(pipes_fd[2][0]);
// 		close(pipes_fd[0][0]);

//         // Execute CMD
// 		exe_arguments = NULL;
//         exe_arguments = ft_split(argvs[3], ' ');
//         if (!exe_arguments) {
//             ft_close_all_pipes(pipes_fd, cmds + 1);
//             exit(-333);
//         }
//         char *path_cmd = ft_strjoin("/bin/", exe_arguments[0]);
//         if (!path_cmd) {
//             ft_close_all_pipes(pipes_fd, cmds + 1);
//             exit(-333);
//         }
//         execve(path_cmd, exe_arguments, NULL);
//     }
	
//     // Close all pipes in the parent process
//     close(pipes_fd[0][0]);
//     close(pipes_fd[1][0]);
//     close(pipes_fd[1][1]);
//     close(pipes_fd[2][1]);

//     // Wait for children to complete
//     wait(NULL);
	
// 	result_str = read_input(pipes_fd[2][0]);
//     close(pipes_fd[2][0]);
//     return result_str;
// }



int main(int argc, char **argv)
{
	int pipe_fd[2];
	// int pid;

	int inputfd;
	// int outfd;
	char **arguments;

	inputfd = open(argv[1], O_RDONLY);

	if (inputfd < 0)
	{
		ft_printf("%s: %s", strerror(errno), argv[1]);
		close(inputfd);
		return (1);		
	}
	// TODO: cmds coutnter + otput_fd_opener
	int cmds = argc - 3;
	char *tempRes = ft_exe_cmd(argv, inputfd, cmds);
	ft_printf("%s", tempRes);
	free(tempRes);
	// close(inputfd);	
}

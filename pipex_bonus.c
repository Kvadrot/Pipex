/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:58:35 by itykhono          #+#    #+#             */
/*   Updated: 2024/06/14 15:57:39 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*read_input(int inputfd)
{
	char	*result;

	result = get_next_line(inputfd);
	close(inputfd);
	return (result);
}

static void	ft_close_all_pipes(int **all_pipes, int pipe_num, int *exception)
{
	int	i;

	i = 0;
	while (i < pipe_num)
	{
		if (!exception || all_pipes[i][0] != *exception)
		{
			close(all_pipes[i][0]);
		}
		if (!exception || all_pipes[i][1] != *exception)
		{
			close(all_pipes[i][1]);
		}
		i++;
	}
}

static int	ft_fill_pipes(int pipe_amount, int **created_pipes)
{
	int	i;

	i = 0;
	while (i < pipe_amount)
	{
		if (pipe(created_pipes[i]) == -1)
		{
			while (i >= 0)
			{
				close(created_pipes[i][1]);
				close(created_pipes[i][0]);
				i--;
			}
			ft_printf("%s", strerror(errno));
			return (-242);
		}
		i++;
	}
	return (200);
}

void	*ft_handle_error(int *all_pipes[2], int pipes_amount)
{
	ft_close_all_pipes(all_pipes, pipes_amount, NULL);
	ft_printf("%s", strerror(errno));
	return (NULL);
}

static int	**ft_craete_all_pipes(int pip_amount)
{
	int	**all_pipes;
	int	i;
	int	j;

	all_pipes = (int **)malloc((pip_amount) * sizeof(int *));
	if (!all_pipes)
		return (NULL);
	i = 0;
	while (i < pip_amount)
	{
		all_pipes[i] = (int *)ft_calloc(sizeof(int), 2);
		if (all_pipes[i] == NULL)
		{
			perror("malloc failed");
			j = 0;
			while (j < i)
			{
				free(all_pipes[j]);
				j++;
			}
			free(all_pipes);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (ft_fill_pipes(pip_amount, all_pipes) == -242)
		return (ft_handle_error(all_pipes, pip_amount));
	return (all_pipes);
}

char	*ft_exe_cmd(char **argvs, int infile_fd, int cmds)
{
	char	**exe_arguments;
	char	*path_cmd;
	int		pid;
	int		cmd_index;
	int		**pipes_fd;

	cmd_index = 0;
	pipes_fd = ft_craete_all_pipes(cmds + 1);
	if (!pipes_fd)
		return (NULL);
	if (read_input_and_write_into_pipe(infile_fd, pipes_fd[0][1]) < 0)
		return (NULL);
	pid = 2;
	while (cmd_index < cmds)
	{
		if (pid > 0)
			pid = fork();
		if (pid < 0)
		{
			ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
			ft_printf("%s", strerror(errno));
			return (NULL);
		}
		if (pid == 0)
		{
			if (dup2(pipes_fd[cmd_index][0], STDIN_FILENO) < 0)
			{
				ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
				ft_printf("dup2 failed for stdin in child: %s\n", strerror(errno));
				ft_free_duble_array_int(pipes_fd, cmds + 1);
				return (NULL);
			}
			if (dup2(pipes_fd[cmd_index + 1][1], STDOUT_FILENO) < 0)
			{
				ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
				ft_free_duble_array_int(pipes_fd, cmds + 1);
				ft_printf("dup2 failed for stdout in child: %s\n", strerror(errno));
				return (NULL);
			}
			ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
			exe_arguments = ft_split(argvs[cmd_index + 2], ' ');
			if (!exe_arguments)
			{
				ft_free_duble_array_int(pipes_fd, cmds + 1);
				exit (-333);
			}
			path_cmd = ft_strjoin("/bin/", exe_arguments[0]);
			if (!path_cmd)
			{
				ft_free_duble_array_char(exe_arguments);
				ft_free_duble_array_int(pipes_fd, cmds + 1);
				exit (-334);
			}
			if (execve(path_cmd, exe_arguments, NULL) == -1)
			{
				ft_free_duble_array_char(exe_arguments);
				ft_free_duble_array_int(pipes_fd, cmds + 1);
				free(path_cmd);
				exit(-335);
			}
		}
		cmd_index++;
	}
	ft_close_all_pipes(pipes_fd, cmds + 1, &(pipes_fd[cmds][0]));
	wait(NULL);
	path_cmd = read_input(pipes_fd[cmds][0]);
	close(pipes_fd[cmds][0]);
	ft_free_duble_array_int(pipes_fd, cmds + 1);
	return (path_cmd);
}

int	main(int argc, char **argv)
{
	int		inputfd;
	int		output_fd;
	int		return_status;
	int		cmds;
	char	*temp_res;

	return_status = 0;
	inputfd = open(argv[1], O_RDONLY);
	if (inputfd < 0)
	{
		ft_printf("%s: %s", strerror(errno), argv[1]);
		close(inputfd);
		return (1);
	}
	cmds = argc - 3;
	temp_res = ft_exe_cmd(argv, inputfd, cmds);
	if (ft_save_to_output_fd(argv[argc -1], temp_res) < 0)
		return_status = 0;
	free(temp_res);
	return (return_status);
}

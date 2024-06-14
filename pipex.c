/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:23 by itykhono          #+#    #+#             */
/*   Updated: 2024/06/14 19:36:26 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static void	ft_close_all_pipes(int **all_pipes, int pipe_num, int *exception)
// {
// 	int	i;

// 	i = 0;
// 	while (i < pipe_num)
// 	{
// 		if (!exception || all_pipes[i][0] != *exception)
// 		{
// 			close(all_pipes[i][0]);
// 		}
// 		if (!exception || all_pipes[i][1] != *exception)
// 		{
// 			close(all_pipes[i][1]);
// 		}
// 		i++;
// 	}
// }

// void	ft_fill_pipes(int pipe_amount, int **created_pipes)
// {
// 	int	i;

// 	i = 0;
// 	while (i < pipe_amount)
// 	{
// 		if (pipe(created_pipes[i]) == -1)
// 		{
// 			while (i >= 0)
// 			{
// 				close(created_pipes[i][1]);
// 				close(created_pipes[i][0]);
// 				i--;
// 			}
// 			ft_printf("%s", strerror(errno));
// 			exit(20);
// 		}
// 		i++;
// 	}
// }

// static int	**ft_craete_all_pipes(int pip_amount)
// {
// 	int	**all_pipes;
// 	int	i;
// 	int	j;

// 	all_pipes = (int **)malloc((pip_amount) * sizeof(int *));
// 	if (!all_pipes)
// 		return (NULL);
// 	i = 0;
// 	while (i < pip_amount)
// 	{
// 		all_pipes[i] = (int *)ft_calloc(sizeof(int), 2);
// 		if (all_pipes[i] == NULL)
// 		{
// 			ft_printf("malloc failed\n");
// 			ft_free_duble_array_int(all_pipes, i);
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// 	ft_fill_pipes(pip_amount, all_pipes);
// 	return (all_pipes);
// }

static	char	**get_args(int **pipes_fd, int cmd_index, int cmds, char **argv)
{
	char	**exe_arguments;
	char	*path_cmd;

	if (dup2(pipes_fd[cmd_index][0], STDIN_FILENO) < 0)
	{
		ft_printf("%s\n", strerror(errno));
		ft_free_duble_array_int(pipes_fd, cmds + 1);
		exit(2);
	}
	if (dup2(pipes_fd[cmd_index + 1][1], STDOUT_FILENO) < 0)
	{
		ft_free_duble_array_int(pipes_fd, cmds + 1);
		ft_printf("%s\n", strerror(errno));
		exit(3);
	}
	ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
	exe_arguments = ft_split(argv[cmd_index + 2], ' ');
	if (!exe_arguments)
	{
		ft_free_duble_array_int(pipes_fd, cmds + 1);
		exit(4);
	}
	return (exe_arguments);
}

static void	ft_execute(char *path, char **exe_argument, int cmds, int **pipes)
{
	if (!path)
	{
		ft_free_duble_array_char(exe_argument);
		ft_free_duble_array_int(pipes, cmds + 1);
		exit(5);
	}
	if (execve(path, exe_argument, NULL) == -1)
	{
		ft_free_duble_array_char(exe_argument);
		ft_free_duble_array_int(pipes, cmds + 1);
		free(path);
		ft_printf("%s\n", strerror(errno));
		exit(6);
	}
}

void	process_commnads(int pid, int **pipes_fd, int cmds, char **argvs)
{
	char	**exe_arguments;
	char	*path_cmd;
	int		cmd_index;

	cmd_index = 0;
	while (cmd_index < cmds)
	{
		if (pid > 0)
			pid = fork();
		if (pid < 0)
		{
			ft_printf("%s", strerror(errno));
			ft_free_duble_array_int(pipes_fd, cmds + 1);
			exit(1);
		}
		if (pid == 0)
		{
			exe_arguments = get_args(pipes_fd, cmd_index, cmds, argvs);
			path_cmd = ft_strjoin("/bin/", exe_arguments[0]);
			ft_execute(path_cmd, exe_arguments, cmds, pipes_fd);
		}
		cmd_index++;
	}
}

char	*ft_exe_cmd(char **argvs, int infile_fd, int cmds)
{
	char	*path_cmd;
	int		pid;
	int		**pipes_fd;

	pipes_fd = ft_craete_all_pipes(cmds + 1);
	if (!pipes_fd)
		exit(1);
	if (read_input_and_write_into_pipe(infile_fd, pipes_fd[0][1]) < 0)
	{
		ft_close_all_pipes(pipes_fd, cmds + 1, NULL);
		ft_free_duble_array_int(pipes_fd, cmds + 1);
		return (NULL);
	}
	pid = 2;
	process_commnads(pid, pipes_fd, cmds, argvs);
	ft_close_all_pipes(pipes_fd, cmds + 1, &(pipes_fd[cmds][0]));
	wait(NULL);
	path_cmd = ft_read_fd(pipes_fd[cmds][0]);
	close(pipes_fd[cmds][0]);
	ft_free_duble_array_int(pipes_fd, cmds + 1);
	return (path_cmd);
}

int	main(int argc, char **argv)
{
	int		inputfd;
	int		return_status;
	int		cmds;
	char	*temp_res;

	return_status = 1;
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

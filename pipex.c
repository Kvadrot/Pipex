/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:23 by itykhono          #+#    #+#             */
/*   Updated: 2024/05/19 19:29:27 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int ft_get_outfile_fd(char *filename) {
	int fd;
	fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	return (fd);
}

int main(int argc, char **argv)
{
	int pipe_fd[2];
	int pid;

	int inputfd;
	int outfd;
	char **arguments;

	inputfd = open(argv[1], O_RDONLY);
	if (inputfd < 0)
	{
		ft_printf("%s: %s", strerror(errno), argv[1]);
		close(inputfd);
		return (1);		
	}
	if (dup2(inputfd, STDIN_FILENO) < 0)
	{
		ft_printf("%s", strerror(errno));
		close(inputfd);
		return (2);
	}
	close(inputfd);	

	arguments = ft_split(argv[2], ' ');
	if (!arguments)
		return (1);
	char *path_cmd = ft_strjoin("/bin/", arguments[0]);
	
	if (pipe(pipe_fd) == -1) {
		ft_printf("%s", strerror(errno));
		return 1;
	}

	pid = fork();
	if (pid < 0) {
		ft_printf("%s", strerror(errno));
		return 2;
	}
	if (pid == 0) {
		outfd = ft_get_outfile_fd(argv[3]);
		if (outfd == -1)
			return (4);

		if (dup2(outfd, STDOUT_FILENO) < 0)
		{
			ft_printf("%s", strerror(errno));
			close(outfd);
			return (5);
		}

		// pid = fork();
		// if (pid < 0) {
		// ft_printf("%s", strerror(errno));
		// return 2;
		// }
		// if (pid == 0)
		// 	execve(path_cmd, arguments, NULL);
		// else
		// 	wait(NULL);
		execve(path_cmd, arguments, NULL);
	} else {
		for (int a = 0; arguments[a] != NULL; a++)
			free(arguments[a]);
		free(arguments);
		free(path_cmd);
		wait(NULL);
	}
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:23 by itykhono          #+#    #+#             */
/*   Updated: 2024/05/18 18:21:39 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

// static char *get_infileName(char **argv)
// {
// 	char *result_name;
// 	if (strncmp(argv[1], "here_doc", strlen("here_doc")))
// 	{
// 		result_name = argv[2];
// 	} else {
// 		result_name = argv[1];
// 	}
// 	return (result_name);
// }

// int main(int argc, char **argv )
// {
// 	int	fd;
// 	int	pipefd[2];
// 	char *infile_name;

// 	if (argc == 1)
// 		return (1);
// 	else if (ft_validate_cmd_syntax(argv) == 200)
// 	{
// 		infile_name = get_infileName;
// 		fd = open(infile_name, O_RDONLY);
// 		if (fd == -1)
// 		{
// 			ft_printf("%s: %s", strerror(errno), argv[1]);
// 			return (1);
// 		}
// 	}

// 	if (pipe(pipefd) == -1)
// 	{
// 		ft_printf("%s", strerror(errno));
// 		return (1);
// 	}

// 	//TODO: READ the input file;Zz
// 	// write(pipefd[1], )
	
// }

int main(int argc, char **argv)
{
	// int pipe_fd[2];
	// int pid;

	// if (pipe(pipe_fd) == -1)
	// 	return 1;
	// pid = fork();
	// if (pid < 0)
	// 	return 2;

	int inputfd;
	int duplicatedfd;
	char *cmd;
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
	char *path_cmd = ft_strjoin("/bin/", arguments[0]);
	execve(path_cmd, arguments, NULL);
}
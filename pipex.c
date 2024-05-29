/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:23 by itykhono          #+#    #+#             */
/*   Updated: 2024/05/29 19:42:03 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int ft_get_outfile_fd(char *filename) {
	int fd;
	fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	return (fd);
}


// char    *ft_exe_cmd(char **argvs, int infile_fd) {
//     char **exe_arguments;
//     int pid_forChild;
//     int i;
//     char *result;
//     int pipe_fd[2];
//     char content[10];

//     result = NULL;
//     exe_arguments = NULL;

//     // Create MainPipe
//     if (pipe(pipe_fd) == -1) {
//         ft_printf("%s", strerror(errno));
//         return NULL;
//     }

// 	//TODO: Read till the end of file
//     if ((read(infile_fd, content, 10)) < 0) {
//         ft_printf("wrong read\n");
//         return (NULL);
//     }

//     // Rewrite from the infile into MainPipe.write
//     write(pipe_fd[1], content, 10);
//     close(infile_fd);

//     // Create Child Process
//     pid_forChild = fork();
//     if (pid_forChild < 0) {
//         ft_printf("%s", strerror(errno));
//         return (NULL);
//     }



//     if (pid_forChild == 0) {
//         // Child process
//         i = 2;
//         ft_printf("child Process is running\n");
		
//         while (argvs[i] != NULL) {
//             // Create GrandChild Process

//             int grandChild = fork();
//             if (grandChild < 0) {
//                 ft_printf("%s", strerror(errno));
//                 return (NULL);
//             }

// 			if (grandChild == 0) {

// 			if (dup2(pipe_fd[0], STDIN_FILENO) < 0) {
// 				ft_printf("Here is %s", strerror(errno));
// 				close(pipe_fd[0]);
// 				close(pipe_fd[1]);
// 				exit(-111);
// 			}
// 			close(pipe_fd[0]); // Close read end in child after loop

// 			int execProcess = fork();
// 			if (execProcess < 0) {
//                 ft_printf("%s", strerror(errno));
//                 return (NULL);
//             }
// 			if (execProcess == 0)
// 			{
// 				if (dup2(pipe_fd[1], STDOUT_FILENO) < 0) {
// 				ft_printf("%s", strerror(errno));
// 				close(pipe_fd[0]);
// 				close(pipe_fd[1]);
// 				exit(-111);
// 				}
// 				close(pipe_fd[1]);
// 				exe_arguments = ft_split(argvs[i], ' ');
// 				if (!exe_arguments) {
//           	      exit(-333);
// 				}
// 				char *path_cmd = ft_strjoin("/bin/", exe_arguments[0]);
//           	  // Execute CMD
// 			  execve(path_cmd, exe_arguments, NULL);
// 			}
// 			wait(NULL);
// 			close(pipe_fd[1]); // Close write end in grandchild after dup
//             // Prepare CMD arguments


//             } else {
//                 // ChildProcess is waiting for Grandchild
//                 wait(NULL);
//                 i++;
//             }
// 			exit(0);
//         }
//     } else {
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
//         wait(NULL); // Wait for child to finish

//         // Read the result from the pipe
//         // read(pipe_fd[0], content, 10);
//         // close(pipe_fd[0]);
//         // write(1, content, 10);
//     }

//     return (result);
// }
char *read_input(int inputfd) {

	return ("wc");
}

static void ft_close_all_pipes(int all_pipes[][2], int pipes_amount)
{
	int	i;
	i = 0;
	while (i < pipes_amount)
	{
		close(all_pipes[i][0]);
		close(all_pipes[i][1]);
		i++;
	}
}

int	ft_create_pipes(int pipe_amount, int created_pipes[][2])
{
	int i;
	i = 0;
	while (i < pipe_amount)
	{
		pipe(created_pipes[i]);
		if (pipe(created_pipes[i]) == -1) {
			while (i >= 0 && created_pipes[i] != NULL)
			{
				close(created_pipes[i][1]);
				close(created_pipes[i][0]);
				i--;
			}
        	ft_printf("%s", strerror(errno));
        	return -242;
    	}
		i++;	
	}
	printf("pipe_created_counter: %d\n",i);
	return (200);
}
char    *ft_exe_cmd(char **argvs, int infile_fd, int cmds) {
	char	**exe_arguments;
	int		pipes_fd[cmds][2];
	int		child_fd;
	int		grandchild;

	//Create all Pipes
	if (ft_create_pipes(cmds, pipes_fd) == -242)
	{
		ft_printf("%s", strerror(errno));
		return (NULL);
	}
	write(pipes_fd[0][1],read_input(infile_fd), ft_strlen(read_input(infile_fd)));
	close(infile_fd);
	
	if ((child_fd = fork()) < 0)
	{
		ft_close_all_pipes(pipes_fd, cmds);
		ft_printf("%s", strerror(errno));
	}
	close(pipes_fd[0][1]);
	close(pipes_fd[0][0]);

	//ONLY CHILD ACCESS
	if (child_fd == 0)
	{
		// Create GrandChild Process
		int grandChild = fork();
		if (grandChild < 0) {
			ft_close_all_pipes(pipes_fd, cmds);
			ft_printf("%s", strerror(errno));
			return (NULL);
		}
		close(pipes_fd[0][1]);
		close(pipes_fd[0][0]);
		if (grandChild == 0)
		{
			//redirect input for execve
			if (dup2(pipes_fd[0][0], STDIN_FILENO) < 0);
			{
				ft_close_all_pipes(pipes_fd, cmds);
				ft_printf("%s", strerror(errno));
				// close(pipes_fd[0][1]);
				// close(pipes_fd[0][0]);
				return (NULL);
			}
			close(pipes_fd[0][0]);
			close(pipes_fd[0][1]);

			//redirect output for execve
			if ( dup2(pipes_fd[1][1], STDIN_FILENO) < 0);
			{
				ft_close_all_pipes(pipes_fd, cmds);
				ft_printf("%s", strerror(errno));
				// close(pipes_fd[1][1]);
				// close(pipes_fd[1][0]);
				return (NULL);
			}
			close(pipes_fd[1][0]);
			close(pipes_fd[1][1]);

			exe_arguments = ft_split(argvs[2], ' ');
			if (!exe_arguments) {
				ft_close_all_pipes(pipes_fd, cmds);
				ft_printf("%s", strerror(errno));
				exit(-333);
			}
			char *path_cmd = ft_strjoin("/bin/", exe_arguments[0]);
			if (!path_cmd)
			{
				ft_close_all_pipes(pipes_fd, cmds);
				ft_printf("%s", strerror(errno));
				exit(-333);
			}
			// Execute CMD
			execve(path_cmd, exe_arguments, NULL);
		} else {
			//Child Process is waiting for its children
			wait(NULL);
			read(pipes_fd[0][0], );
		}
	} else {
		//MAIN Process is waiting for its children
		wait(NULL);
	}
}


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
	ft_exe_cmd(argv, inputfd, argc - 3);
	close(inputfd);	
}

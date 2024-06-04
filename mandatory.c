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



// int main(int argc, char **argv)
// {
// 	int pipe_fd[2];
// 	// int pid;

// 	int inputfd;
// 	// int outfd;
// 	char **arguments;

// 	inputfd = open(argv[1], O_RDONLY);

// 	if (inputfd < 0)
// 	{
// 		ft_printf("%s: %s", strerror(errno), argv[1]);
// 		close(inputfd);
// 		return (1);		
// 	}
// 	// TODO: cmds coutnter + otput_fd_opener
// 	int cmds = argc - 3;
// 	char *tempRes = ft_exe_cmd(argv, inputfd, cmds);
// 	ft_printf("%s", tempRes);
// 	free(tempRes);
// 	// close(inputfd);	
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:23 by itykhono          #+#    #+#             */
/*   Updated: 2024/05/23 20:35:17 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int ft_get_outfile_fd(char *filename) {
    int fd;
    fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    return (fd);
}

void ft_execute_command(char *cmd, int infile_fd, int pipe_fd[2]) {
    char **exe_arguments;
    int grandChild;
    
    exe_arguments = ft_split(cmd, ' ');
    if (!exe_arguments) {
        perror("Error allocating memory for arguments");
        exit(EXIT_FAILURE);
    }
    char *path_cmd = ft_strjoin("/bin/", exe_arguments[0]);
    
    grandChild = fork();
    if (grandChild < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (grandChild == 0) {
        // Grandchild process
        if (dup2(infile_fd, STDIN_FILENO) < 0 || dup2(pipe_fd[1], STDOUT_FILENO) < 0) {
            perror("dup2 failed");
            exit(EXIT_FAILURE);
        }
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execve(path_cmd, exe_arguments, NULL);
        perror("execve failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        waitpid(grandChild, NULL, 0);
        close(pipe_fd[1]);
        free(path_cmd);
        for (int i = 0; exe_arguments[i] != NULL; i++) {
            free(exe_arguments[i]);
        }
        free(exe_arguments);
    }
}

char *ft_exe_cmd(char **argvs, int infile_fd) {
    int pipe_fd[2];
    char *result = NULL;

    if (pipe(pipe_fd) == -1) {
        perror("Pipe failed");
        return NULL;
    }

    ft_execute_command(argvs[2], infile_fd, pipe_fd);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    
    return result;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <command>\n", argv[0]);
        return 1;
    }

    int inputfd = open(argv[1], O_RDONLY);
    if (inputfd < 0) {
        perror(argv[1]);
        return 1;
    }

    ft_exe_cmd(argv, inputfd);
    close(inputfd);
    
    return 0;
}

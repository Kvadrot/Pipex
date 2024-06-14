/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:16 by itykhono          #+#    #+#             */
/*   Updated: 2024/06/14 14:38:45 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h> // For S_IRUSR and S_IWUSR

# include "./lib_ft/libft.h"
# include "./lib_ft_printf/ft_printf.h"
# include "./get_next_line_final/get_next_line.h" 

int		ft_save_to_output_fd(char *filename, char *result);
int		read_input_and_write_into_pipe(int inputfd, int pipe_fd);
void	ft_free_duble_array_char(char **arr);
void	ft_free_duble_array_int(int **arr, int arr_num);

#endif
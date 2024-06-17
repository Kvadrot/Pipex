/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:59:52 by itykhono          #+#    #+#             */
/*   Updated: 2024/06/17 15:03:05 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "./lib_ft/libft.h"
# include "./lib_ft_printf/ft_printf.h"
# include "./get_next_line_final/get_next_line.h"

int		**ft_craete_all_pipes(int pip_amount);
int		ft_save_to_output_fd(char *filename, char *result);
int		read_input_and_write_into_pipe(int inputfd, int pipe_fd);
void	ft_free_duble_array_char(char **arr);
void	ft_free_duble_array_int(int **arr, int arr_num);
char	*ft_read_fd(int inputfd);
void	ft_close_all_pipes(int **all_pipes, int pipe_num, int *exception);
void	ft_fill_pipes(int pipe_amount, int **created_pipes);
#endif
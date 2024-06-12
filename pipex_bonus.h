/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:59:52 by itykhono          #+#    #+#             */
/*   Updated: 2024/06/12 15:00:23 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h> // For S_IRUSR and S_IWUSR


// # ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# include "./lib_ft/libft.h"
# include "./lib_ft_printf/ft_printf.h"
# include "./get_next_line_final/get_next_line.h" 

void	ft_print_err(int err_code);
void	jtest(void);

int	ft_validate_cmd_syntax(char **argv);
char *readfile_till_the_end(int filefd, int *len);

#endif
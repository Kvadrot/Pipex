/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:16 by itykhono          #+#    #+#             */
/*   Updated: 2024/05/05 21:54:54 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>


# include "./lib_ft/libft.h"

void	ft_print_err(int err_code);
void	ft_print(char *str);
void	jtest(void);

int	ft_validate_cmd_syntax(char **argv);


# endif
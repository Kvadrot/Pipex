/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:01:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/05/06 15:23:10 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_print_err(int err_code)
{
	if (err_code == -401)
		perror("wrong instructions for infile");
	else
		ft_printf("promox");
}
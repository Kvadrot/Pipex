/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:27:27 by itykhono          #+#    #+#             */
/*   Updated: 2024/06/14 19:38:48 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

void	ft_close_all_pipes(int **all_pipes, int pipe_num, int *exception)
{
	int	i;

	i = 0;
	while (i < pipe_num)
	{
		if (!exception || all_pipes[i][0] != *exception)
		{
			close(all_pipes[i][0]);
		}
		if (!exception || all_pipes[i][1] != *exception)
		{
			close(all_pipes[i][1]);
		}
		i++;
	}
}

void	ft_fill_pipes(int pipe_amount, int **created_pipes)
{
	int	i;

	i = 0;
	while (i < pipe_amount)
	{
		if (pipe(created_pipes[i]) == -1)
		{
			while (i >= 0)
			{
				close(created_pipes[i][1]);
				close(created_pipes[i][0]);
				i--;
			}
			ft_printf("%s", strerror(errno));
			exit(20);
		}
		i++;
	}
}

int	**ft_craete_all_pipes(int pip_amount)
{
	int	**all_pipes;
	int	i;
	int	j;

	all_pipes = (int **)malloc((pip_amount) * sizeof(int *));
	if (!all_pipes)
		return (NULL);
	i = 0;
	while (i < pip_amount)
	{
		all_pipes[i] = (int *)ft_calloc(sizeof(int), 2);
		if (all_pipes[i] == NULL)
		{
			ft_printf("malloc failed\n");
			ft_free_duble_array_int(all_pipes, i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_fill_pipes(pip_amount, all_pipes);
	return (all_pipes);
}
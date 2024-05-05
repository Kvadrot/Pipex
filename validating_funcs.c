/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:58:51 by itykhono          #+#    #+#             */
/*   Updated: 2024/05/05 22:28:32 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_validate_cmd_syntax(char **argv)
{
	int fd;

	if (ft_strncmp( argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		printf("TODO: LIMITER HANDLER\n");
	} else {
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(strerror(errno));
			// ft_print("%s: %s", strerror(errno), argv[1]);
			return (-800);
		}
		close(fd);
		return (200);
	}
}
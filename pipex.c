/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:16:23 by itykhono          #+#    #+#             */
/*   Updated: 2024/05/05 22:17:20 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"


static char *get_infileName(char **argv)
{
	char *result_name;
	ft_print_err(-401);
	
	result_name = "ssss";
	return (result_name);
}

int main(int argc, char **argv )
{
	int	fd;
	char *infile_name;

	if (argc == 1)
		return (0);
	else if (ft_validate_cmd_syntax(argv) == 200)
	{
		infile_name = get_infileName(argv);
	}
	// fd = open();

}
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   utilities.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/05/09 13:48:24 by itykhono          #+#    #+#             */
// /*   Updated: 2024/05/17 18:47:54 by itykhono         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

int	ft_save_to_output_fd(char *filename, char *result)
{
	int	output_fd;
	int	len;
	int	printed_sym;

	printed_sym = 0;
	output_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (output_fd < 0) {
		ft_printf("%d", strerror(errno));
        return (-210);
    }
	if (!result)
		len = 0;
	else
		len = ft_strlen(result);
	printed_sym = write(output_fd, result, len);
	if (printed_sym == -1)
	{
		ft_printf("%s", strerror(errno));
		return(-211);
	}
	close(output_fd);
	return (0);
}

int	read_input_and_write_into_pipe(int inputfd, int pipe_fd) {
	char	*result;
	int		len;

	result = get_next_line(inputfd);
	if (!result)
		len = 0;
	else
		len = ft_strlen(result);
	
    if (write(pipe_fd, result, len) == -1)
	{
		ft_printf("%s", strerror(errno));
		return (-202);
	}
	close(inputfd);
	close(pipe_fd);
	free(result);
	return(0);
}


void	ft_free_duble_array_int(int **arr, int arr_num)
{
	int	arr_ind;

	arr_ind = 0;
	if (arr == NULL) {
        return;
    }
	while (arr_ind < arr_num)
	{
		if (arr[arr_ind] != NULL)
			free(arr[arr_ind]);
		arr_ind++;
	}
	free(arr);
}

void	ft_free_duble_array_char(char **arr)
{
	int	arr_ind;

	arr_ind = 0;
	if (arr == NULL) {
        return;
    }
	while (arr[arr_ind] != NULL)
	{
		if (arr[arr_ind] != NULL)
			free(arr[arr_ind]);
		arr_ind++;
	}
	free(arr);
}
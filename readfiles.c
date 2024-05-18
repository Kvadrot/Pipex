/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:48:24 by itykhono          #+#    #+#             */
/*   Updated: 2024/05/17 18:47:54 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strjoin(char **joined, char *s2, int s1len, int s2len)
{
	char	*newstr;
	int		ind;
	int		s2_ind;

	ind = 0;
	newstr = (char *)malloc((s1len + s2len) * sizeof(char) + 1);
	if (!newstr)
		return (0);
	while (ind < s1len)
	{
		newstr[ind] = (*joined)[ind];
		ind ++;
	}
	s2_ind = 0;
	while (s2_ind < s2len)
	{
		newstr[ind] = s2[s2_ind];
		ind++;
		s2_ind++;
	}
	newstr[ind] = '\0';
	free (*joined);
	*joined = newstr;
	return (1);
}


char *readfile_till_the_end(int filefd, int *contentlen)
{
	char *buffer[BUFFER_SIZE];
	char *filecontent;
	int bytestoread;

	bytestoread = read(filefd, buffer, BUFFER_SIZE);
	if (bytestoread = -1)
	{
		ft_printf("%s", strerror(errno));
		return (NULL);
	}
	*contentlen += bytestoread;
	if (!filecontent)
		return (NULL);
	while (ft_strchr(buffer, '\0') == NULL)
	{
		bytestoread = read(filefd, buffer, BUFFER_SIZE);
		if (bytestoread = -1)
		{
			ft_printf("%s", strerror(errno));
			return (NULL);
		}
		*contentlen += bytestoread;
	}
	filecontent =  malloc(sizeof(char) * *contentlen);

	return (filecontent);	
}

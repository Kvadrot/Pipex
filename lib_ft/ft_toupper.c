/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:15:44 by itykhono          #+#    #+#             */
/*   Updated: 2024/03/07 13:37:57 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_toupper(int c)
{
	if (ft_isalpha(c) == 0)
		return (c);
	else if (c >= 97 && c <= 122)
		return (c -= 32);
	return (c);
}

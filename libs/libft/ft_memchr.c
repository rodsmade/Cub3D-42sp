/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:35:56 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/13 13:40:36 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		if (((unsigned char *)b)[index] == (unsigned char)c)
			return ((unsigned char *)b + index);
		index++;
	}
	return (0);
}

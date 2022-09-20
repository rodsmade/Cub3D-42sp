/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:49:36 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/13 03:41:22 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i_src;
	size_t	i_dest;
	size_t	i;

	i = 0;
	i_src = ft_strlen(src);
	i_dest = 0;
	if (!dest && !src)
		return (0);
	while (dest[i_dest] && i_dest < size)
		i_dest++;
	if (i_dest >= size)
		return (i_dest + i_src);
	while (src[i] && (i_dest + i) < size - 1)
	{
		dest[i_dest + i] = src[i];
		i++;
	}
	dest[i_dest + i] = '\0';
	return (i_dest + i_src);
}

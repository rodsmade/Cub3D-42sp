/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 02:54:38 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/10 03:11:32 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	character;

	index = ft_strlen(s);
	character = (char)c;
	while (index >= 0)
	{
		if (s[index] == character)
			return ((char *)s + index);
		index--;
	}
	return (0);
}

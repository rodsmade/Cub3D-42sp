/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:11:01 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/13 14:30:19 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_ltl;
	size_t	aux;

	i_big = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	while (big[i_big] && i_big < len)
	{
		i_ltl = 0;
		while (big[i_big + i_ltl] == little[i_ltl] && (i_big + i_ltl) < len)
		{
			aux = i_big;
			if (ft_strlen(little) == i_ltl + 1)
				return ((char *)big + aux);
			i_ltl++;
		}
		i_big++;
	}
	return (0);
}

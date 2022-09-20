/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 00:00:39 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/14 22:08:50 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	size_t	index;
	size_t	strlen;

	if (!str)
		return ;
	strlen = ft_strlen(str);
	index = 0;
	while (index < strlen)
	{
		f(index, &str[index]);
		index++;
	}
}

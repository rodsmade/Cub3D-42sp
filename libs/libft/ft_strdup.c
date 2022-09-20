/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 03:05:07 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/13 23:10:11 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*string;
	size_t	index;

	index = 0;
	string = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!string)
		return (0);
	while (str[index])
	{
		string[index] = str[index];
		index++;
	}
	string[index] = '\0';
	return (string);
}

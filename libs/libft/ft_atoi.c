/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 01:17:04 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/20 03:06:40 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const	char *str)
{
	int	result;
	int	index;
	int	signal;

	index = 0;
	result = 0;
	signal = 1;
	while ((str[index] >= '\t' && str[index] <= '\r') || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			signal = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	return (result * signal);
}

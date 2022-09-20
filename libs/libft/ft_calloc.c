/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 02:51:50 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/20 03:20:30 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*result;

	if (number * size > 2147483647)
		return (NULL);
	result = malloc(number * size);
	if (result == 0)
		return (0);
	ft_memset(result, 0, number * size);
	return (result);
}

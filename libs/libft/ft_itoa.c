/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 21:21:45 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/20 03:49:37 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	isabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	revalue(char *number)
{
	size_t	start;
	size_t	end;
	char	aux;

	start = 0;
	end = ft_strlen(number) - 1;
	while (number[start] && start < end)
	{
		aux = number[start];
		number[start] = number[end];
		number[end] = aux;
		end--;
		start++;
	}
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*string;
	size_t	is_n;

	is_n = (n < 0);
	if (n == 0)
		return (ft_strdup("0"));
	string = ft_calloc(sizeof(char), ((intlen(n) + is_n) + 1));
	if (!string)
		return (NULL);
	size = 0;
	while (n != 0)
	{
		string[size++] = '0' + isabs(n % 10);
		n /= 10;
	}
	if (is_n)
		string[size] = '-';
	revalue(string);
	return (string);
}

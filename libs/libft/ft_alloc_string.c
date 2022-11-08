/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:00:39 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/31 06:00:46 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_alloc_string(int str_size, int init_value)
/**
 * @brief allocates `str_size` bytes for a string, appends a terminating '\0',
 * and initialises every byte in the string to `init_value`.
 */
{
	char	*str;
	int		i;

	str = malloc((str_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < str_size)
		str[i] = init_value;
	str[i] = '\0';
	return (str);
}

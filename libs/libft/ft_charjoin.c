/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:11:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/29 22:13:26 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(const char* str, const char c)
{
	int	i;
	char *joined_str;

	if (!str)
		return (NULL);
	joined_str = malloc((ft_strlen(str) + 1 + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	i = -1;
	while (str[++i])
		joined_str[i] = str[i];
	joined_str[i] = c;
	joined_str[++i] = '\0';
	ft_free_ptr((void *)&str);
	return (joined_str);
}

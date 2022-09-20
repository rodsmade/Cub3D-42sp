/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:58:44 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/14 19:50:19 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	frst_char(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	last_char(const char *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (i + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*strnew;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = frst_char(s1, set);
	end = last_char(&s1[start], set);
	strnew = ft_substr(s1, start, end);
	return (strnew);
}

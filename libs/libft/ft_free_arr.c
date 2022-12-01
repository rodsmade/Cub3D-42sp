/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:45:12 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/29 21:45:14 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arr(void ***arr)
{
	int	i;

	i = -1;
	if (*arr != NULL)
	{
		while ((*arr)[++i])
		{
			ft_free_ptr((void *)&(*arr)[i]);
			(*arr)[i] = NULL;
		}
		free(*arr);
	}
}

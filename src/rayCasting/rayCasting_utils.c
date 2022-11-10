/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:56:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/10 17:45:10 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_buf_with_zero(t_mlx_struct *mlx, int x)
{
	int	y;

	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			mlx->ray->buf[x][y] = 0;
			y++;
		}
		x++;
	}
}

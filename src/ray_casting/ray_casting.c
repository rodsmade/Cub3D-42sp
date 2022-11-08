/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:13:53 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/25 14:44:11 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"


int	raycasting(t_raycasting *ray, t_data *data)
{
	calc_ray_casting(ray, 0, data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:35:47 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/21 10:39:37 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keystrokes_management(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy(data);
	return (0);
}

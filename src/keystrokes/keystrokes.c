/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystrokes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:04:38 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/01 18:04:38 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keystrokes_management(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy(data);
	if (keycode == XK_Left || keycode == XK_Right)
		rotate_view(keycode, data);
	if (keycode == XK_a || keycode == XK_w
		|| keycode == XK_d || keycode == XK_s)
		move_player(keycode, data);
	return (0);
}

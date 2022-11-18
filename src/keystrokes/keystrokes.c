/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   key_press.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gusalves <gusalves@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/09/21 10:35:47 by gusalves		  #+#	#+#			 */
/*   Updated: 2022/09/21 10:39:37 by gusalves		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_view(int keycode, t_data *data)
{
	double old_dir_x;
	double old_plane_x;

	//rotate to the right
	if (keycode == XK_Right)
	{
		//both camera direction and camera plane must be rotated
		old_dir_x = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(-data->ray.rot_speed) - data->ray.dir_y * sin(-data->ray.rot_speed);
		data->ray.dir_y = old_dir_x * sin(-data->ray.rot_speed) + data->ray.dir_y * cos(-data->ray.rot_speed);
		old_plane_x = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rot_speed) - data->ray.plane_y * sin(-data->ray.rot_speed);
		data->ray.plane_y = old_plane_x * sin(-data->ray.rot_speed) + data->ray.plane_y * cos(-data->ray.rot_speed);
	}
	//rotate to the left
	if (keycode == XK_Left)
	{
		//both camera direction and camera plane must be rotated
		old_dir_x = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(data->ray.rot_speed) - data->ray.dir_y * sin(data->ray.rot_speed);
		data->ray.dir_y = old_dir_x * sin(data->ray.rot_speed) + data->ray.dir_y * cos(data->ray.rot_speed);
		old_plane_x = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(data->ray.rot_speed) - data->ray.plane_y * sin(data->ray.rot_speed);
		data->ray.plane_y = old_plane_x * sin(data->ray.rot_speed) + data->ray.plane_y * cos(data->ray.rot_speed);
	}
}

void	move_player(int keycode, t_data *data)
{
	//move forward if no wall in front of you
	if (keycode == XK_w)
	{
		if(world_map_char[(int)(data->ray.pos_x + data->ray.dir_x * data->ray.move_speed)][(int)data->ray.pos_y] == '0')
			data->ray.pos_x += data->ray.dir_x * data->ray.move_speed;
		if(world_map_char[(int)data->ray.pos_x][(int)(data->ray.pos_y + data->ray.dir_y * data->ray.move_speed)] == '0')
			data->ray.pos_y += data->ray.dir_y * data->ray.move_speed;
	}
	//move backwards if no wall behind you
	if (keycode == XK_s)
	{
		if(world_map_char[(int)(data->ray.pos_x - data->ray.dir_x * data->ray.move_speed)][(int)data->ray.pos_y] == '0')
			data->ray.pos_x -= data->ray.dir_x * data->ray.move_speed;
		if(world_map_char[(int)data->ray.pos_x][(int)(data->ray.pos_y - data->ray.dir_y * data->ray.move_speed)] == '0')
			data->ray.pos_y -= data->ray.dir_y * data->ray.move_speed;
	}
	// //move left if no wall in front of you
	// if (keycode == XK_a)
	// {
	// 	if(world_map_char[(int)data->ray.pos_x][(int)(data->ray.pos_y + data->ray.dir_y * data->ray.move_speed)] == '0')
	// 		data->ray.pos_x += data->ray.dir_x * data->ray.move_speed;
	// 	if(world_map_char[(int)data->ray.pos_x][(int)(data->ray.pos_y + data->ray.dir_y * data->ray.move_speed)] == '0')
	// 		data->ray.pos_y += data->ray.dir_y * data->ray.move_speed;
	// }
	// //move right if no wall behind you
	// if (keycode == XK_d)
	// {
	// 	if(world_map_char[(int)(data->ray.pos_x - data->ray.dir_x * data->ray.move_speed)][(int)data->ray.pos_y] == '0')
	// 		data->ray.pos_x -= data->ray.dir_x * data->ray.move_speed;
	// 	if(world_map_char[(int)data->ray.pos_x][(int)(data->ray.pos_y - data->ray.dir_y * data->ray.move_speed)] == '0')
	// 		data->ray.pos_y -= data->ray.dir_y * data->ray.move_speed;
	// }
}

int	keystrokes_management(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy(data);
	if (keycode == XK_Left || keycode == XK_Right)
		rotate_view(keycode, data);
	if (keycode == XK_a || keycode == XK_w || keycode == XK_d || keycode == XK_s)
		move_player(keycode, data);
	return (0);
}

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

void	rotate_view(int keycode, t_mlx_struct *mlx)
{
	double old_dir_x;
	double old_plane_x;

	//rotate to the right
	if (keycode == XK_Right)
	{
		//both camera direction and camera plane must be rotated
		old_dir_x = mlx->ray->dir_x;
		mlx->ray->dir_x = mlx->ray->dir_x * cos(-mlx->ray->rot_speed) - mlx->ray->dir_y * sin(-mlx->ray->rot_speed);
		mlx->ray->dir_y = old_dir_x * sin(-mlx->ray->rot_speed) + mlx->ray->dir_y * cos(-mlx->ray->rot_speed);
		old_plane_x = mlx->ray->plane_x;
		mlx->ray->plane_x = mlx->ray->plane_x * cos(-mlx->ray->rot_speed) - mlx->ray->plane_y * sin(-mlx->ray->rot_speed);
		mlx->ray->plane_y = old_plane_x * sin(-mlx->ray->rot_speed) + mlx->ray->plane_y * cos(-mlx->ray->rot_speed);
	}
	//rotate to the left
	if (keycode == XK_Left)
	{
		//both camera direction and camera plane must be rotated
		old_dir_x = mlx->ray->dir_x;
		mlx->ray->dir_x = mlx->ray->dir_x * cos(mlx->ray->rot_speed) - mlx->ray->dir_y * sin(mlx->ray->rot_speed);
		mlx->ray->dir_y = old_dir_x * sin(mlx->ray->rot_speed) + mlx->ray->dir_y * cos(mlx->ray->rot_speed);
		old_plane_x = mlx->ray->plane_x;
		mlx->ray->plane_x = mlx->ray->plane_x * cos(mlx->ray->rot_speed) - mlx->ray->plane_y * sin(mlx->ray->rot_speed);
		mlx->ray->plane_y = old_plane_x * sin(mlx->ray->rot_speed) + mlx->ray->plane_y * cos(mlx->ray->rot_speed);
	}
}

void	move_player(int keycode, t_mlx_struct *mlx)
{
	//move forward if no wall in front of you
	if (keycode == XK_w)
	{
		if(world_map_char[(int)(mlx->ray->pos_x + mlx->ray->dir_x * mlx->ray->move_speed)][(int)mlx->ray->pos_y] == '0')
			mlx->ray->pos_x += mlx->ray->dir_x * mlx->ray->move_speed;
		if(world_map_char[(int)mlx->ray->pos_x][(int)(mlx->ray->pos_y + mlx->ray->dir_y * mlx->ray->move_speed)] == '0')
			mlx->ray->pos_y += mlx->ray->dir_y * mlx->ray->move_speed;
	}
	//move backwards if no wall behind you
	if (keycode == XK_s)
	{
		if(world_map_char[(int)(mlx->ray->pos_x - mlx->ray->dir_x * mlx->ray->move_speed)][(int)mlx->ray->pos_y] == '0')
			mlx->ray->pos_x -= mlx->ray->dir_x * mlx->ray->move_speed;
		if(world_map_char[(int)mlx->ray->pos_x][(int)(mlx->ray->pos_y - mlx->ray->dir_y * mlx->ray->move_speed)] == '0')
			mlx->ray->pos_y -= mlx->ray->dir_y * mlx->ray->move_speed;
	}
	// //move left if no wall in front of you
	// if (keycode == XK_a)
	// {
	// 	if(world_map_char[(int)mlx->ray->pos_x][(int)(mlx->ray->pos_y + mlx->ray->dir_y * mlx->ray->move_speed)] == '0')
	// 		mlx->ray->pos_x += mlx->ray->dir_x * mlx->ray->move_speed;
	// 	if(world_map_char[(int)mlx->ray->pos_x][(int)(mlx->ray->pos_y + mlx->ray->dir_y * mlx->ray->move_speed)] == '0')
	// 		mlx->ray->pos_y += mlx->ray->dir_y * mlx->ray->move_speed;
	// }
	// //move right if no wall behind you
	// if (keycode == XK_d)
	// {
	// 	if(world_map_char[(int)(mlx->ray->pos_x - mlx->ray->dir_x * mlx->ray->move_speed)][(int)mlx->ray->pos_y] == '0')
	// 		mlx->ray->pos_x -= mlx->ray->dir_x * mlx->ray->move_speed;
	// 	if(world_map_char[(int)mlx->ray->pos_x][(int)(mlx->ray->pos_y - mlx->ray->dir_y * mlx->ray->move_speed)] == '0')
	// 		mlx->ray->pos_y -= mlx->ray->dir_y * mlx->ray->move_speed;
	// }
}

int	keystrokes_management(int keycode, t_mlx_struct *mlx)
{
	if (keycode == KEY_ESC)
		destroy(mlx);
	if (keycode == XK_Left || keycode == XK_Right)
		rotate_view(keycode, mlx);
	if (keycode == XK_a || keycode == XK_w || keycode == XK_d || keycode == XK_s)
		move_player(keycode, mlx);
	return (0);
}

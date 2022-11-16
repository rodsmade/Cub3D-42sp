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

int	keystrokes_management(int keycode, t_mlx_struct *mlx)
{
	if (keycode == KEY_ESC)
		destroy(mlx);
	return (0);
}

//    readKeys();
// 	//move forward if no wall in front of you
// 	if (keyDown(SDLK_UP))
// 	{
// 	  if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
// 	  if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
// 	}
// 	//move backwards if no wall behind you
// 	if (keyDown(SDLK_DOWN))
// 	{
// 	  if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
// 	  if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
// 	}
// 	//rotate to the right
// 	if (keyDown(SDLK_RIGHT))
// 	{
// 	  //both camera direction and camera plane must be rotated
// 	  double oldDirX = dirX;
// 	  dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
// 	  dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
// 	  double oldPlaneX = planeX;
// 	  planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
// 	  planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
// 	}
// 	//rotate to the left
// 	if (keyDown(SDLK_LEFT))
// 	{
// 	  //both camera direction and camera plane must be rotated
// 	  double oldDirX = dirX;
// 	  dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
// 	  dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
// 	  double oldPlaneX = planeX;
// 	  planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
// 	  planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
// 	}
//   }
// }
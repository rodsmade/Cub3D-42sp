/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/20 22:17:53 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", argv[1]);
	void *mlx_ptr = mlx_init();
	printf("%p\n", mlx_ptr);
}

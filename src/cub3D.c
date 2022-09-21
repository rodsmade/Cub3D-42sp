/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/21 19:58:04 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void validate_args(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		print_err_exit(WRONG_ARG_NO);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		print_err_exit(FILE_EXT_ERR);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_err_exit(SYSCALL_ERR);
	close(fd);
	return ;
}

int	main(int argc, char **argv)
{
	t_mlx_struct	mlx;

	validate_args(argc, argv);
	mlx.pointer = mlx_init();
	window(&mlx);
	mlx_loop(mlx.pointer);
	(void) mlx;
	return (0);
}

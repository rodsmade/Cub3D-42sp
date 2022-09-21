/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:42 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/21 19:47:35 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ------------------------------------------------		INCLUDES	-----------

# include "libft.h"				// libft
# include "mlx.h"				// minilibx
# include <stdio.h>				// printf(), perror()
# include <errno.h>				// errno (macro)
# include <string.h>			// strerror()
# include <sys/types.h>			// open()
# include <sys/stat.h>			// open()
# include <fcntl.h>				// open()
# include <stdlib.h> 			// exit()
# include "ansi_color_codes.h"	// colours 🌈

# define KEY_ESC	65307		// ESC keycode

// ------------------------------------------------		STRUCTS		-----------

typedef struct s_mlx_struct
{
	void	*pointer;
	void	*window;
}				t_mlx_struct;

// ------------------------------------------------		ENUMS		-----------

enum e_http_method {
	SYSCALL_ERR,
	WRONG_ARG_NO,
	FILE_EXT_ERR
};


// ------------------------------------------------		PROTOTYPES	-----------
// error_handling.c
void	print_err_exit(int errcode);

// window.c
void	window(t_mlx_struct *mlx);

// destroy.c
int		destroy(t_mlx_struct *mlx);

// key_press.c
int		keystrokes_management(int keycode, t_mlx_struct *mlx);

#endif

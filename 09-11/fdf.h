/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:22:05 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/11 15:12:02 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# include "minilib/mlx.h" // библиотека minilibx
# include "libft/includes/libft.h"
# include <math.h>

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define WIDTH 1000
# define HEIGHT 1000

typedef struct		s_fdf
{
	char			*name;
	int				fd;
	int				x;
	int				y;
	int				z;
	int				**map;
	int				**color;
	int				offset_x;
	int				offset_y;
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
	struct s_fdf	*next;

	int				size_map;
}					t_fdf;

void				print_menu(t_fdf *lst);
void				iso(int *x, int *y, int z);
void				draw_line(int x, int y, int x1, int y1, t_fdf *lst);
void				draw_map(t_fdf *lst);

#endif

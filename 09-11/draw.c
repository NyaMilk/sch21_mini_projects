/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:42:07 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/11 15:53:05 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define MAX(a, b) (a > b ? a : b)
# define ABS(a) ((a > 0) ? a : -a)

void		iso(int *x, int *y, int z)
{
	int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
    *y = (previous_x + previous_y) * sin(00.523599) - z;
}

void		draw_line(int x, int y, int x1, int y1, t_fdf *lst)
{
	int step_x;
	int step_y;
	int max;
	// int z;
	// int z1;

	x *= lst->size_map;
    y *= lst->size_map;
    x1 *= lst->size_map;
    y1 *= lst->size_map;

	// z = lst->map[y][x];
	// z1 = lst->map[y1][x1];
	// if (z || z1)
	// 	lst->color = 0xff0000;
	// else
	// 	lst->color = 0xffffff;

	// iso(&x, &y, z);
    // iso(&x1, &y1, z1);

	step_x = x1 - x;
	step_y = y1 - y;
	// printf("x: %d\n", step_x);
	// printf("y: %d\n", step_y);
    max = MAX(ABS(step_x), ABS(step_y));
	// printf("max: %d\n", max);
    step_x /= max;
	// printf("x1: %d\n", step_x);
    step_y /= max;
	// printf("y1: %d\n", step_y);
	while ((x - x1) || (y - y1))
	{
		mlx_pixel_put(lst->mlx_ptr, lst->win_ptr, x, y, 0xffffff);
		x += step_x;
		y += step_y;
	}
}

void		draw_map(t_fdf *lst)
{
	int		x;
	int		y;
	
	y = 0;
	while (y < lst->y)
	{
		x = 0;
		while (x < lst->x)
		{
			if (x < lst->x - 1)
				draw_line(x, y, x + 1, y, lst);
			if (y < lst->y - 1)
				draw_line(x, y, x, y + 1, lst);
			x++;
		}
		y++;
	}
}

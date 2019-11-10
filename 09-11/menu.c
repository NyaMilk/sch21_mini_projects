/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:04:56 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/10 19:25:13 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf *lst)
{
	void	*mlx;
	void	*win;
	int y = 0;

	mlx = lst->mlx_ptr;
	win = lst->win_ptr;
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 40, y += 30, 0xffffff, "LITTLE CAT");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Yolo");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 20, y += 20, 0xffffff, "Holo");
}

/*
How to Use
Rotate:
Zoom:
Color:
*/
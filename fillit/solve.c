/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:30:29 by mgrass            #+#    #+#             */
/*   Updated: 2019/10/22 16:48:06 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	overlay_tetr(char **map, t_tetr *lst)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		x = lst->block[i] + lst->offset_x;
		y = lst->block[i + 1] + lst->offset_y;
		if (map[y][x] != '.')
			return (1);
		i += 2;
	}
	return (0);
}

static void	put_tetr(char **map, t_tetr *lst, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		map[lst->block[i + 1] + lst->offset_y]
		[lst->block[i] + lst->offset_x] = c;
		i += 2;
	}
}

static int	check_map(t_tetr *lst, char **map, int size)
{
	if (!lst)
		return (1);
	lst->offset_x = 0;
	lst->offset_y = 0;
	while (size > lst->block[7] + lst->offset_y)
	{
		while (size > lst->block[6] + lst->offset_x)
		{
			if (!overlay_tetr(map, lst))
			{
				put_tetr(map, lst, lst->letter);
				if (check_map(lst->next, map, size))
					return (1);
				else
					put_tetr(map, lst, '.');
			}
			lst->offset_x++;
		}
		lst->offset_x = 0;
		lst->offset_y++;
	}
	return (0);
}

static char	**create_map(int map_size)
{
	char	**map;
	int		k;

	k = 0;
	if (!(map = (char **)malloc(sizeof(char *) * map_size)))
		return (NULL);
	while (k < map_size)
	{
		map[k] = ft_strnew(map_size);
		ft_memset(map[k], '.', map_size);
		k++;
	}
	return (map);
}

void		solve_file(t_tetr *head)
{
	char	**map;
	int		map_size;

	map_size = min_size(count_tetr(head));
	map = create_map(map_size);
	while (!check_map(head, map, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = create_map(map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}

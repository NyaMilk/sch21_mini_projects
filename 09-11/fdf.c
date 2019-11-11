/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrass <mgrass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:21:20 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/11 15:48:09 by mgrass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int keycode, void *param)//закрывает окошко пр  нажатии клавиши еск.Возможно нужно переделать
{
    if(!param && keycode == 53)
        exit(0);
    return (0);
}

void		error_out(void)
{
	ft_putendl("error");
	exit(1);
}

int			check_color(char *line)
{
	int		count;

	count = 0;
	line++;
	if (*line && *line != '0')
		error_out();
	line++;
	if (*line && *line != 'x')
		error_out();
	line++;
	count += 2;
	while (*line && *line != ' ')
	{
		if ((*line < 'A' || *line > 'F') && (*line < 'a' || *line > 'f') &&
		(*line < '0' || *line > '9'))
			error_out();
		line++;
		count++;
	}
	if (count != 8 && count != 6 && count != 4) // какие цвета еще могут быть? 0xff 0xff00
		error_out();
	return (count);
}

void		check_line(char *line)
{
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (*line == '-')
			line++;
		if (*line < '0' || *line > '9')
			error_out();
		while (*line != '\0' && *line >= '0' && *line <= '9')
			line++;
		if (*line == ',')
			line += check_color(line) + 1;
		if (*line && *line != ' ')
			error_out();
		while (*line && *line == ' ')
			line++;
	}
}

int			check_size(t_fdf *lst, char *line)
{
	char	**tmp;
	int		x;

	x = 0;
	check_line(line);
	tmp = ft_strsplit(line, ' ');
	while (tmp[x])
		free(tmp[x++]);
	if (lst->y == 0)
		lst->x = x;
	else
	{
		if (x != lst->x)
			return (0);
	}
	free(line);
	free(tmp);
	lst->y++;
	return (1);
}

void		get_color(char *tmp, t_fdf *lst, int x, int y)
{
	char	**ptr;

	lst->color = ft_memalloc(sizeof(int *) * lst->y);
	lst->color[y] = ft_memalloc(sizeof(int) * lst->x);
	ptr = ft_strsplit(tmp, ',');
	// printf("split ptr0: %s\n", ptr[0]);
	// printf("split ptr1: %s\n", ptr[1]);
	if (ptr[1])
	{
		// printf("->z: %d\n", lst->z);
		lst->color[y][x] = ft_atoi_base(ptr[1] + 2, 16);
		// printf("->color: %d\n", lst->color[y][x]);
		free(ptr[1]);
	}
	else
		lst->color[y][x] = 0xffffff;
	// printf("->color: %d\n", lst->color[y][x]);
	free(ptr[0]);
	free(ptr);
	// фри фри фри
}

void		create_map(t_fdf *lst)
{
	char	*line;
	char	**tmp;
	int		x;
	int		y;

	y = 0;
	while ((get_next_line(lst->fd, &line)) == 1)
	{
		x = 0;
		tmp = ft_strsplit(line, ' ');
		lst->map[y] = ft_memalloc(sizeof(int) * lst->x);
		// printf("-----\n");
		while (tmp[x])
		{
			get_color(tmp[x], lst, x, y);
			printf("c: %d\n", lst->color[y][x]);
			lst->map[y][x] = ft_atoi(tmp[x]);
			free(tmp[x++]);
		}
		free(tmp);
		y++;
	}
}

t_fdf		*read_file(char *s)
{
	t_fdf	*lst;
	char	*line;

	if (!(lst = (t_fdf *)malloc(sizeof(t_fdf))))
		error_out();
	lst->x = 0;
	lst->y = 0;
	lst->name = s;
	lst->mlx_ptr = mlx_init();
	lst->win_ptr = mlx_new_window(lst->mlx_ptr, WIDTH, HEIGHT, "little_cat");
	if ((lst->fd = open(s, O_RDONLY)) < 0)
		error_out();
	while ((get_next_line(lst->fd, &line)) == 1)
	{
		if (!(check_size(lst, line)))
			error_out();
	}
	lst->map = ft_memalloc(sizeof(int *) * lst->y);
	close(lst->fd);
	lst->fd = open(lst->name, O_RDONLY);
	return (lst);
}

// ----- проверка чтения карты -----
char		print_map(t_fdf *lst)
{
	int		x;
	int		y;

	y = 0;
	while (y < lst->y)
	{
		x = 0;
		while (x < lst->x)
			printf("%d ", lst->map[y][x++]);
		printf("\n");
		y++;
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_fdf	*lst;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf file");
		exit(1);
	}
	if (!(lst = read_file(av[1])))
		error_out();
	create_map(lst);
	
	// ----- проверка чтения карты -----
	// print_map(lst);
	
	//----- удалить -----
	lst->size_map = 20;
	
	print_menu(lst);
	draw_map(lst);
	mlx_hook(lst->win_ptr, 2, 0, key_press, ((void *)0));
	mlx_loop(lst->mlx_ptr);
	return (0);
}

#include "fdf.h"
#include <stdio.h>

void			error_out(void)
{
	ft_putendl("error");
	exit(1);
}

int deal_key(int key, t_fdf *lst)
{
	ft_putstr(key);

	if (key == 126)
		lst->offset_y -= 10;
	if (key == 125)
		lst->offset_y += 10;
	if (key == 123)
		lst->offset_x -= 10;
	if (key == 124)
		lst->offset_x += 10;
	mlx_clear_window(lst->mlx_ptr, lst->win_ptr);
	draw(lst);
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
	lst = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(av[1], lst);
	// if (!(lst = (t_fdf *)malloc(sizeof(t_fdf))))
	// 	error_out();
	// draw(lst);
	// mlx_key_hook(lst->win_ptr, deal_key, lst);
	// mlx_loop(lst->mlx_ptr);


// прочитать файл
	// int i;
	// int j;

	// i = 0;
	// j = 0;
	// while (i < lst->y_coord)
	// {
	// 	j = 0;
	// 	while (j < lst->x_coord)
	// 	{
	// 		printf("%d ", lst->z_coord[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	// return (0);

// нарислвать линию (функции для открытия окна)
	lst->mlx_ptr = mlx_init();
	lst->win_ptr = mlx_new_window(lst->mlx_ptr, 800, 800, "FDF");
	lst->zoom = 20;
//	draw_line(10, 10, 600, 300, lst);
	draw(lst);
	mlx_key_hook(lst->win_ptr, deal_key, lst); // кнопочки для бонуса
	mlx_loop(lst->mlx_ptr); //держит окно открытым
}
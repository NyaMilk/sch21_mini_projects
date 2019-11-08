#include "test.h"

void		ft_error(char *msg)
{
	if (msg != NULL)
	{
		ft_putstr(msg);
		ft_putchar('\n');
	}
	exit(1);
}

int		check_color(char *line)
{
	int	i;

	i = 0;
	// printf("linecolor: %s\n", line);
	line++;
	// printf("linecolor2: %s\n", line);
	if (*line && *line != '0')
		ft_error("ERROR color");
	line++;
	i++;
	if (*line && *line != 'x')
		ft_error("ERROR color");
	line++;
	i++;
	while (*line && *line != ' ')
	{
		if ((*line < 'A' || *line > 'F') && (*line < 'a' || *line > 'f') &&
				(*line < '0' || *line > '9'))
			ft_error("ERROR color");
		line++;
		i++;
	}
	// printf("i: %d\n", i);
	if (i != 8 && i != 6 && i != 4)
		ft_error("ERROR color");
	return (i);
}

void		check_line(char *line)
{
	while (*line)
	{
		// printf("line start: %s\n", line);
		while (*line && *line == ' ')
			line++;
		if (*line == '-')
			line++;
		// printf("line: %s\n", line);
		if (*line < '0' || *line > '9')
			ft_error("ERROR line");
		while (*line != '\0' && *line >= '0' && *line <= '9')
			line++;
		// if (*line == '\0')
		// 	break ;
		// printf("line: %s\n", line);
		if (*line == ',')
			line += check_color(&(*line)) + 1;
		// printf("line2: %s\n", line);
		// if (*line == '\0')
		// 	break ;
		if (*line && *line != ' ')
			ft_error("ERROR line");
		while (*line && *line == ' ')
			line++;
	}
}

static int	init_tab(t_info *info, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	check_line(line);
	tab = ft_strsplit(line, ' ');
	// printf("split: %s\n", tab[2]);
	// printf("->color: %d\n", color);
	while (tab[x])
		free(tab[x++]);
	// printf("x: %d\n", x);
	// printf("y: %d\n", info->lines);
	if (info->lines == 0)
	{
		info->rows = x;
		// printf("rows: %d\n", info->rows);
	}
	else
	{
		// printf("xer: %d\n", info->rows);
		// printf("yer: %d\n", x);
		if (x != info->rows)
			return (-1);
	}
	free(line);
	free(tab);
	info->lines++;
	return (0);
}

static void	init_info(t_info *info)
{
	char	*line;

	line = NULL;
	info->lines = 0;
	info->rows = 0;
	while ((get_next_line(info->fd, &line)) == 1)
	{
		if (init_tab(info, line) == -1)
			ft_error("ERR: The number of elements per line aren't consistent");
	}
	info->map = ft_memalloc(sizeof(int*) * info->lines);
	close(info->fd);
	info->fd = open(info->name, O_RDONLY);
}

void get_color(char *tmp, t_info *info)
{
	char **ptr;

	ptr = ft_strsplit(tmp, ',');
	printf("splitptr: %s\n", ptr[0]);
	if (ptr[1])
	{
		info->color = ft_atoi_base(ptr[1] + 1, 16);
		printf("->color: %d\n", info->color);
	}
	// else
	// 	info->color = 0xFF0000;

}

void		parser(t_info *info)
{
	char	*line;
	char	**tab;
	int 	x;
	int 	y;
	
	y = 0;
	init_info(info);
	while ((get_next_line(info->fd, &line)) == 1)
	{
		x = 0;
		tab = ft_strsplit(line, ' ');
	// printf("splittab: %s\n", tab[2]);
		info->map[y] = ft_memalloc(sizeof(int) * info->rows);
	printf("111\n");
		while (tab[x])
		{
			get_color(tab[x], info);
			info->map[y][x] = ft_atoi(tab[x]);
			free(tab[x]);
			x++;
			// printf("->color: %d\n", info->color);
		}
		free(tab);
		y++;
	}
	// printf("while: %d\n", info->map[2][2]);
	// if (x[2] == -1)
	// 	ft_error("ERROR: get_next_line returned <:-1:>");
}

t_info			*info_init(char	*path)
{
	t_info	*a;

	// a = NULL;
	a = (t_info *)malloc(sizeof(t_info));
	a->name = path;
	// a->mlx = mlx_init();
	// a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "FdF");
	a->fd = open(path, O_RDONLY);
	// printf("%s\n", path);
	if (a->fd <= 2)
		ft_error(ft_strjoin("No file ", path));
	return (a);
}

char print_map(t_info *a)
{
    int i;
	int j;
	i = 0;
	j = 0;
	while (i < a->lines)
	{
		j = 0;
		while (j < a->rows)
		{
			printf("%d ", a->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_info	*a;

	if (ac != 2)
		ft_error("Usage: ./fdf filename");
	a = info_init(av[1]);
	parser(a);
	// a->frame = 0;
	// draw(a);
	// mlx_key_hook(a->win, &ft_keypress_hook, a);
	// mlx_loop(a->mlx);
    print_map(a);
	// printf("col: %d\n", a->color);
}

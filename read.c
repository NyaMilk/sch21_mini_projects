#include "fdf.h"

static int		ft_wdcount(char *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static int get_height(char *str)
{
	char	*line;
	int		fd;
	int height;

	height = 0;
	fd = open(str, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static int get_width(char *str)
{
	char	*line;
	int		fd;
	int width;

	fd = open(str, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_wdcount(line, ' ');
	free(line);
	close(fd);
	return (width);
}

static void fill_matrix(int *z_line, char *line)
{
	char **num;
	int i;

	num = ft_strsplit(line, ' ');
	i = 0;
	while(num[i])
	{
		z_line[i] = ft_atoi(num[i]);
		// printf("z_line: %ls \n", z_line);
		free(num[i]);
		i++;
	}
	free(num);
	// printf("z_line2: %ls \n", z_line);
}

void	read_file(char *str, t_fdf *lst)
{
	int fd;
	char *line;
	int i;

	lst->y_coord = get_height(str);
	printf("y: %d \n", lst->y_coord);
	lst->x_coord = get_width(str);
	printf("x: %d \n", lst->x_coord);
	lst->z_coord = (int **)malloc(sizeof(int *) * lst->y_coord + 1);
	printf("1\n");
	i = 0;
	while(i <= lst->y_coord)
		lst->z_coord[i++] = (int *)malloc(sizeof(int) * lst->x_coord + 1);
	printf("z1: %ls \n", lst->z_coord[i]);
	fd = open(str, O_RDONLY);
	printf("fd: %d \n", fd);
	i = 0;
	// printf("line: %s \n", line);
	while(get_next_line(fd, &line) == 1)
	{
		fill_matrix(lst->z_coord[i], line);
		// printf("line1: %s \n", line);
		free(line);
		i++;
	}
	// free(line);
	// printf("line: %s \n", line);
	close(fd);
	lst->z_coord[i] = NULL;
}

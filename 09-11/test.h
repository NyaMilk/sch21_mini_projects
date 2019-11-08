#ifndef FDF_H
# define FDF_H

# include <stdio.h>
// # include "mlx.h"
# include <math.h>
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"

# define WIDTH 1560
# define HEIGHT 1300

# define WHITE 0x00FFFFFF

# define ESC_CODE 65307
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define RELIEF_IN 91
# define RELIEF_OUT 84
# define RESTART 15
# define COLOR 3
# define ARROWS(key) (key >= 123 && key <= 126)

# define MVTOEND(list) while (list) list = list->next

# define ERROR(msg, nb, val) if (nb != ft_arrlen(val)) ft_error(msg);

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	char			*name;
	int				fd;
	int				**map;
	int				lines;
	int				rows;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				frame;
	int				color;
}					t_info;

int					ft_keypress_hook(int keycode, t_info *key);
void				parser(t_info *info);
void				draw(t_info *drawl);

#endif
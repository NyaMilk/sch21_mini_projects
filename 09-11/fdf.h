#ifndef FDF_H
# define FDF_H

# include <stdio.h>

# include "minilibx/mlx.h"
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define WIDTH 800
# define HEIGHT 800

typedef struct		s_fdf
{
	char			*name;
	int				fd;
    int				x;
    int				y;
	int				z;
    int				**map;
	int				color;
	int				offset_x;
	int				offset_y;
	void			*win_ptr;
    void			*mlx_ptr;
	void			*img_ptr;
	struct s_fdf	*next;
}					t_fdf;

#endif
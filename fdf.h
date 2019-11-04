#ifndef FDF_H
# define FDF_H

#include "minilibx/mlx.h"
#include "libft/includes/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct		s_fdf
{
    int				x_coord;
    int				y_coord;
    int				**z_coord;
	int				zoom;
	int				color;
	int				offset_x;
	int				offset_y;
	void			*win_ptr;
    void			*mlx_ptr;
	struct s_fdf	*next;
}					t_fdf;

void	read_file(char *str, t_fdf *lst);

#endif
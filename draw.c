#include "fdf.h"
#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

float mod (float i)
{
    return((i < 0) ? -i : i);
}

void draw_metr(float*x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *x = (*x + *y) * sin(0.8) - z;
}

void draw_line(float x, float y, float x1, float y1, t_fdf *lst)
{
    //[1:1] [3:5]
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    z = lst->z_coord[(int)y][(int)x];
    z1 = lst->z_coord[(int)y1][(int)x1];

    // ZOOM
    x *= lst->zoom;
    y *= lst->zoom;
    x1 *= lst->zoom;
    y1 *= lst->zoom;

    // COLOR
    lst->color = (z || z1) ? 0xe80c0c : 0xffffff;

    // 3D
    draw_metr(&x, &y, z);
    draw_metr(&x1, &y1, z1);

    // offset
    x += lst->offset_x;
    y += lst->offset_y;
    x1 += lst->offset_x;
    y1 += lst->offset_y;;

    x_step = x1 - x; // 2
    y_step = y1 - y; // 4
    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    //пиксель на поле
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(lst->mlx_ptr, lst->win_ptr, x, y, lst->color);
        x += x_step;
        y += y_step;
    }
}

void    draw(t_fdf *lst)
{
    int x;
    int y;

    y = 0;
    while (y < lst->y_coord)
    {
        x = 0;
        while (x < lst->x_coord)
        {
            if (x < lst->x_coord - 1)
                draw_line(x, y, x + 1, y, lst);
            if (y < lst->y_coord - 1)
                draw_line(x, y, x, y + 1, lst);
            x++;
        }
        y++;
    }
}


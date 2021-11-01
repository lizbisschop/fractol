#include "fractol.h"

void       julia(t_all *all)
{
    double c_re, c_im;
    double new_re, new_im, old_re, old_im;
    double zoom = 1, move_x = 0, move_y = 0;
    int    color;
    int     max_iterations;
    int     x;
    int     y;
    int     i;
    int     r;
    int     g;
    int     b;

    y = 0;
    c_re = -0.7;
    c_im = 0.27015;
    // while (1)
    // {
        mlx_hook(all->data.mlx_win, 2, 1L<<0, close_window, &all->data);
        while (y < all->data.height)
        {
            x = 0;
            while (x < all->data.width)
            {
                i = 0;
                new_re = 1.5 * (x - all->data.width / 2) / (0.5 * zoom * all->data.width) + move_x;
                new_im = (y - all->data.height / 2) / (0.5 * zoom * all->data.height) + move_y;
                while (i < 500 && (new_re * new_re + old_re * old_re < 4))
                {
                    old_re = new_re;
                    old_im = new_im;
                    new_re = old_re * old_re - old_im * old_im + c_re;
                    new_im = 2 * old_re * old_im + c_im;
                    i++;
                }
                // r = 9 * (1 - i) * pow(i, 3) * 255;
                // g = 15 * pow((1 - i), 2) * pow(i, 2) * 255;
                // b = 8.5 * pow((1 - i), 3) * i * 255;
                // color = create_trgb(r, g, b);
                color = create_trgb(i % 256, 255, 255 * (i < 500));
                my_mlx_pixel_put(&all->data, x, y, i);
                x++;
            }
            y++;
        }
		mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
    // }
}

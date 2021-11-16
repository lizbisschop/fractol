#include "fractol.h"

void       julia(t_all *all)
{
    int    color;
    int     max_iterations;
    int     x;
    int     y;
    int     i;
    int     r;
    int     g;
    int     b;

    y = 0;
    all->fractol.c_re = -0.64;
    all->fractol.c_im = 0.4;
    max_iterations = 400; 
    all->fractol.move_x = 0;
	if (all->data.zoom == 1)
		all->fractol.zoom *= pow(1.001, 110); 
	else if (all->data.zoom == 2)
		all->fractol.zoom /= pow(1.001, 110); 
    while (y < all->data.height)
    {
        x = 0;
        while (x < all->data.width)
        {
            i = 0;
            all->fractol.new_re = 1.5 * (x - all->data.width / 2) / (0.5 * all->fractol.zoom * all->data.width) + all->fractol.move_x;
            all->fractol.new_im = (y - all->data.height / 2) / (0.5 * all->fractol.zoom * all->data.height) + all->fractol.move_y;
            while (i < max_iterations && (all->fractol.new_re * all->fractol.new_re + all->fractol.new_im * all->fractol.new_im < 4))
            {
                all->fractol.old_re = all->fractol.new_re;
                all->fractol.old_im = all->fractol.new_im;
                all->fractol.new_re = all->fractol.old_re * all->fractol.old_re - all->fractol.old_im * all->fractol.old_im + all->fractol.c_re;
                all->fractol.new_im = 2 * all->fractol.old_re * all->fractol.old_im + all->fractol.c_im;
                i++;
            }
            // r = 9 * (1 - i) * pow(i, 3) * 255;
            // g = 15 * pow((1 - i), 2) * pow(i, 2) * 255;
            // b = 8.5 * pow((1 - i), 3) * i * 255;
            //very colorfull shite
            // r = (114-151) * (i - 50) + 151;
            // g = (127-206) * (i  - 50) + 206;
            // b = (157-255) * (i - 50) + 255;
            // color = create_trgb(r, g, b);
            // color = (i) | (i << 8) || (i << 16);
            // printf("%d = i\n", i);
            // printf("color = %d\n", color);
            // color = create_trgb(i % 256, 255, 255 * (i < 500));
            // my_mlx_pixel_put(&all->data, x, y, color);
            colors(all, i, x, y);
            x++;
        }
        y++;
    }
    all->data.zoom = 0;
}

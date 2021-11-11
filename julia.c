#include "fractol.h"

void       julia(t_all *all)
{
    double c_re, c_im;
    double new_re, new_im, old_re, old_im;
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
    max_iterations = 300; 

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
            new_re = 1.5 * (x - all->data.width / 2) / (0.5 * all->fractol.zoom * all->data.width) + all->fractol.move_x;
            new_im = (y - all->data.height / 2) / (0.5 * all->fractol.zoom * all->data.height) + all->fractol.move_y;
            while (i < max_iterations && (new_re * new_re + old_re * old_re < 4))
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
}

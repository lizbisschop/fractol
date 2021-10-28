#include "fractol.h"

void    mandelbrot(t_all *all)
{

	float left, top, xside, yside;
	float xscale, yscale, zx, zy, cx, tempx, cy;
	int color;
	int r;
	int g;
	int b;
    int x, y, i, j;
    int maxx, maxy, itter;

	left = -1.61;
	top = -0.25;
	xside = 0.25;
	yside = 0.45;

	maxx = all->data->height - 1;
	maxy = all->data->width - 1;

	xscale = xside / maxx;
	yscale = yside / maxy;

	y = 0;
	// while (left > -2 && left < 10)
	// {
	// 	// mlx_clear_window(all->data->mlx, all->data->mlx_win);
	// 	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win, all->data->img, 0, 0);
	// 	usleep(1000);
	// 	left -= 0.01;
	// 	top -= 0.01;
	// 	xside = 0.01;
	// 	yside -= 0.01;
		while (y <= maxy)
		{
			x = 0;
			while (x <= maxx)
			{
				cx = x * xscale + left;
				cy = y * yscale + top;
				zx = 0;
				zy = 0;
				itter = 0;
				while ((zx * zx + zy * zy < 4) && itter < 30)
				{
					// printf("x = %d y = %d\t", x, y);
					tempx = zx * zx - zy * zy + cx;
					zy = 2 * zx * zy + cy;
					zx = tempx;
					itter = itter + 1;
				}
				r = 9 * (1 - itter) * pow(itter, 3) * 255;
				g = 15 * pow((1 - itter), 2) * pow(itter, 2) * 255;
				b = 8.5 * pow((1 - itter), 3) * itter * 255;
				color = create_trgb(r, g, b);
				// color = create_trgb(itter, itter * 8, itter);
				// my_mlx_pixel_put(all->data, x, y, itter);
				my_mlx_pixel_put(all->data, x, y, color);
				x++;
			}
			y++;
		}
	// }
}

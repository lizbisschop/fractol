#include "fractol.h"

void		mandelbrot(t_all *all)
{
	double pr, pi;
	double new_re, new_im, old_re, old_im;
	// double zoom = 1, move_x = -0.5, move_y = 0;
	int		max_iterations = 300;
	int i;
	int x;
	int y;
	int color;

	y = 0;
	// if (all->data.zoom == 1)
	// {
	// 	printf("keycode = 4\n");
	// 	all->fractol.zoom *= pow(1.001, 40); 
	// }
	// else if (all->data.zoom == 2)
	// {
	// 	printf("keycode = 5\n");
	// 	all->fractol.zoom /= pow(1.001, 40); 
	// }
	while (y < all->data.height)
	{
		x = 0;
		while (x < all->data.width)
		{
			pr = 1.5 * (x - all->data.width / 2) / (0.5 * all->fractol.zoom * all->data.width) + all->fractol.move_x;
			pi = (y - all->data.height / 2) / (0.5 * all->fractol.zoom * all->data.height) + all->fractol.move_y;
			new_re = 0;
			new_im = 0;
			old_re = 0;
			old_im = 0;
			i = 0;
			while (i < max_iterations && (new_re * new_re + new_im * new_im) < 4)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + pr;
				new_im = 2 * old_re * old_im + pi;
				i++;
			}
			// printf("%f %f\n", all->fractol.new_re, all->fractol.new_im);
			color = create_trgb(i % 256, 255, 255 * (i < 500));
			my_mlx_pixel_put(&all->data, x, y, i);
			x++;
		}
		y++;
	}
}

// void		mandelbrot(t_all *all)
// {
// 	int		max_iterations = 300;
// 	int i;
// 	int x;
// 	int y;
// 	int color;
	
// 	all->fractol.zoom = 0;
// 	all->fractol.move_x = -0.5;
// 	all->fractol.move_x = 0;

// 	// while (1)
// 	// {
// 		// if (all->data.zoom == 1)
// 		// 	all->fractol.zoom *= pow(1.001, 0.22);
// 		// else if (all->data.zoom == 2)
// 		// 	all->fractol.zoom /= pow(1.001, 0.22); 
// 		y = 0;
// 		while (y < all->data.height)
// 		{
// 			x = 0;
// 			while (x < all->data.width)
// 			{
// 				all->fractol.pr = 1.5 * (x - all->data.width / 2) / (0.5 * all->fractol.zoom * all->data.width) + all->fractol.move_x;
// 				all->fractol.pi = (y - all->data.height / 2) / (0.5 * all->fractol.zoom * all->data.height) + all->fractol.move_y;
// 				all->fractol.new_re = 0;
// 				all->fractol.new_im = 0;
// 				all->fractol.old_re = 0;
// 				all->fractol.old_im = 0;
// 				i = 0;
// 				while (i < max_iterations && (all->fractol.new_re * all->fractol.new_re + all->fractol.new_im * all->fractol.new_im) < 4)
// 				{
// 					all->fractol.old_re = all->fractol.new_re;
// 					all->fractol.old_im = all->fractol.new_im;
// 					all->fractol.new_re = all->fractol.old_re * all->fractol.old_re - all->fractol.old_im * all->fractol.old_im + all->fractol.pr;
// 					all->fractol.new_im = 2 * all->fractol.old_re * all->fractol.old_im + all->fractol.pi;
// 					i++;
// 				}
// 				printf("%f %f\n", all->fractol.new_re, all->fractol.new_im);
// 				color = create_trgb(i % 256, 255, 255 * (i < 500));
// 				my_mlx_pixel_put(&all->data, x, y, i);
// 				x++;
// 			}
// 			y++;
// 		}
// 		// mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
// 	// }
// }

// void    mandelbrot(t_all *all)
// {

// 	float left, top, xside, yside;
// 	float xscale, yscale, zx, zy, cx, tempx, cy;
// 	int color;
// 	int r;
// 	int g;
// 	int b;
//     int x, y, i, j;
//     int maxx, maxy, itter;

// 	left = -1.61;
// 	top = -0.25;
// 	xside = 0.25;
// 	yside = 0.45;

// 	maxx = all->data.height - 1;
// 	maxy = all->data.width - 1;

// 	xscale = xside / maxx;
// 	yscale = yside / maxy;

// 	y = 0;
// 	// while (left > -2 && left < 10)
// 	// {
// 	// 	// mlx_clear_window(all->data.mlx, all->data.mlx_win);
// 	// 	usleep(100000);
// 	// 	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
// 	// 	left -= 0.01;
// 	// 	top -= 0.01;
// 	// 	xside = 0.01;
// 	// 	yside -= 0.01;
// 		while (y <= maxy)
// 		{
// 			x = 0;
// 			while (x <= maxx)
// 			{
// 				cx = x * xscale + left;
// 				cy = y * yscale + top;
// 				zx = 0;
// 				zy = 0;
// 				itter = 0;
// 				while ((zx * zx + zy * zy < 4) && itter < 30)
// 				{
// 					// printf("x = %d y = %d\t", x, y);
// 					tempx = zx * zx - zy * zy + cx;
// 					zy = 2 * zx * zy + cy;
// 					zx = tempx;
// 					itter++;
// 				}
// 				r = 9 * (1 - itter) * pow(itter, 3) * 255;
// 				g = 15 * pow((1 - itter), 2) * pow(itter, 2) * 255;
// 				b = 8.5 * pow((1 - itter), 3) * itter * 255;
// 				color = create_trgb(r, g, b);
// 				// color = create_trgb(itter, itter * 8, itter);
// 				// my_mlx_pixel_put(all->data, x, y, itter);
// 				my_mlx_pixel_put(&all->data, x, y, color);
// 				x++;
// 			}
// 			y++;
// 		}
// 	// }
// }

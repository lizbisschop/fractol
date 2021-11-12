#include "fractol.h"

void		colors(t_all *all, int i, int x, int y)
{
	int rgb;
	double c;

	if (i < 300)
	{
		c = fabs((double)(i - 300) / 300 - 1);
		c = (cos(c * 3.13159 + 3.14159) + 1) / 2;
		rgb = create_trgb(c * all->fractol.r, c * all->fractol.g, c * all->fractol.b);
		my_mlx_pixel_put(&all->data, x, y, rgb);
	}
	else
		my_mlx_pixel_put(&all->data, x, y, 0x000000);
}

int		mandelbrot(t_all *all)
{
	double pr, pi;
	double new_re, new_im, old_re, old_im;
	// double all->fractol.zoom = 1, move_x = -0.5, move_y = 0;
	int		max_iterations = 300;
	int i;
	int x;
	int y;
	int r;
	int g;
	int b;


	int color;

	y = 0;
	// printf(" new x = %d old x = %d new y = %d old y = %d\n", all->fractol.new_mouse_x, all->fractol.old_mouse_x, all->fractol.new_mouse_y, all->fractol.old_mouse_y);
	// all->fractol.diff_dist_y = (all->fractol.new_mouse_y - all->fractol.old_mouse_y) * 0.0003;
	// if (all->fractol.diff_dist_y < 0)
	// 	all->fractol.diff_dist_y = all->fractol.diff_dist_y * -1;
	// all->fractol.diff_dist_x = (all->fractol.new_mouse_x -all->fractol.old_mouse_x) * 0.0003;
	// if (all->fractol.diff_dist_x < 0)
	// 	all->fractol.diff_dist_x = all->fractol.diff_dist_x * -1;
	if (all->data.zoom == 1)
		all->fractol.zoom *= pow(1.001, 110); 
	else if (all->data.zoom == 2)
		all->fractol.zoom /= pow(1.001, 110);
		// printf("zoom = %d\n", all->data.zoom);

	//zoom with mouse
	// if (all->data.zoom != 0)
	// {
	// 	if (all->fractol.new_mouse_x < all->fractol.old_mouse_x)
	// 		all->fractol.move_x -= 0.3 * 0.5 / all->fractol.zoom + 0.2; 
	// 	else
	// 		all->fractol.move_x += 0.3 * 0.5 / all->fractol.zoom + 0.2; 
	// 	if (all->fractol.new_mouse_y < all->fractol.old_mouse_y)
	// 		all->fractol.move_y += 0.3 * 0.5 / all->fractol.zoom + 0.2; 
	// 	else
	// 		all->fractol.move_y -= 0.3 * 0.5 / all->fractol.zoom + 0.2;
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
				// my_mlx_pixel_put(&all->data, x, y, 0);
			}
			// printf("%f %f\n", all->fractol.new_re, all->fractol.new_im);
			// color = create_trgb(i % 256, 255, 255 * (i < 300));
			// color = HSVtoRGB(rgb_to_hsv(i % 256, 255, 255 * (i < max_iterations)));
			// HSVtoRGB(i % 256, 255, 255 * (i  < max_iterations), all);
			// color = create_trgb(all->fractol.r, all->fractol.g, all->fractol.b);
			// my_mlx_pixel_put(&all->data, x, y, color);
			r = 9 * (1 - i) * pow(i, 3) * 255;
			g = 15 * pow((1 - i), 2) * pow(i, 2) * 255;
			b = 8.5 * pow((1 - i), 3) * i * 255;

			//very colorful shite
			// r = (114-151) * (i - 900) + 151;
			// g = (127-206) * (i  - 100) + 206;
			// b = (157-255) * (i - 500) + 255;
			// color = (i) | (i << 8) | (i << 16);

			//best till now
			// colors(all, i, x, y);

			color = create_trgb(i * i, i * 100 / 300 + 55, 75);
			// printf("x = %d,  y = %d color = %d\n", x, y, i);
			// if (i == 90)
			// 	color = 0x000000;
			// color = create_trgb(r, g, b);
			// color = create_trgb(i % 256, 255, 255 * (i < 500));
			my_mlx_pixel_put(&all->data, x, y, color);
			x++;
		}
		y++;
	}
	all->fractol.old_mouse_x = all->fractol.new_mouse_x;
	all->fractol.old_mouse_y = all->fractol.new_mouse_y;
	all->data.zoom = 0;
	return (0);
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

#include "fractol.h"

void	clear_window(t_all *all)
{
	int x = 0;
	int y = 0;


	while (y < all->data.height)
	{
		while (x < all->data.width)
		{
			my_mlx_pixel_put(&all->data, x, y, 0);
			x++;
		}
		y++;
	}
}

int 	mouse_press(int keycode, int x, int y, t_all *all)
{
	all->fractol.new_mouse_x = x;
	all->fractol.new_mouse_y = y;
	printf("%d\n", keycode);
	// printf("keycode = %d x = %d y = %d\n", keycode, x , y);
	if (keycode == 4)
		all->data.zoom = 1;
	else if (keycode == 5)
		all->data.zoom = 2;
	else
		all->data.zoom = 0;
	(void)keycode;
	return(0);
}

int		mouse_release(int keycode, int x, int y, t_all *all)
{
	// printf("%d key realease\n", all->data.zoom);
	all->data.zoom = 0;
	return(0);
}

int      close_window(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		// all->data.zoom = 1;
		mlx_destroy_window(all->data.mlx, all->data.mlx_win);
		exit_program("It was very fun have a fractolic time!\n");
	}
	else if (keycode == W_KEY)
		all->fractol.move_y -= 0.3 * 1 / all->fractol.zoom; 
	else if (keycode == S_KEY)
		all->fractol.move_y += 0.3 * 1 / all->fractol.zoom;
	else if (keycode == A_KEY)
		all->fractol.move_x -= 0.3 * 1 / all->fractol.zoom;
	else if (keycode == D_KEY)
		all->fractol.move_x += 0.3 * 1 / all->fractol.zoom;
	get_next_line(0, &all->fractol.color);
	printf("%s\n", all->fractol.color);
	return (0);
}

int		fractol_loop(t_all *all)
{
	which_fractol(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	return (0);
}

int		close_screen(t_all *all)
{
	printf("Window has been closed goodbye\n");
	exit(0);
	return (0);
}

int		main_loop(t_all *all)
{
	mlx_hook(all->data.mlx_win, 2, 1l<<0, close_window, all);
	mlx_hook(all->data.mlx_win, 4, 0, mouse_press, all);
	mlx_hook(all->data.mlx_win, 5, 0, mouse_release, all);
	mlx_hook(all->data.mlx_win, 17, 1l << 17, close_screen, all);
	mlx_loop(all->data.mlx);
	return (0);
}

int     main(int argc, char **argv)
{
	t_all	all;

	if (argc < 3)
	{
		printf("Please enter a right paramater: [kind fractol] [color]\n");
		return (0);
	}
	all.type = ft_strdup(argv[1]);
	all.fractol.color = ft_strdup(argv[2]);


	all.data.height = 1000;
	all.data.width =  1000;
	all.data.mlx = mlx_init();
	all.data.mlx_win = mlx_new_window(all.data.mlx, all.data.height, all.data.width, "Hello-world!");
	all.data.img = mlx_new_image(all.data.mlx, all.data.width, all.data.height);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length, &all.data.endian);
	set_structs(&all);
	mlx_loop_hook(all.data.mlx, &fractol_loop, &all);
	main_loop(&all);

	// mlx_put_image_to_window(all.data.mlx, all.data.mlx_win, all.data.img, 0, 0);
	// (void)argc;
	// (void)argv;
	return (0);
}
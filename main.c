#include "fractol.h"

int 	mouse_press(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	// if (keycode == 4)
	// 	data->zoom = 1;
	// else if (keycode == 5)
	// 	data->zoom = 2;
	return(0);
}

int      close_window(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit_program("It was very fun have a fractolic time!\n");
	}
	return (0);
}

int		fractol_loop(t_all *all)
{
	which_fractol(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	return (0);
}

int		main_loop(t_all *all)
{
	mlx_hook(all->data.mlx_win, 2, 1L<<0, close_window, &all->data);
	mlx_hook(all->data.mlx_win, 4, 0, mouse_press, &all->data);
	mlx_loop(all->data.mlx);
	return (0);
}

int     main(int argc, char **argv)
{
	t_all	all;

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
	(void)argc;
	(void)argv;
	return (0);
}
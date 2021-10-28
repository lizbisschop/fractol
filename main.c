#include "fractol.h"

int     main(int argc, char **argv)
{
	int		i = 0;
	t_data	data;
	t_all	all;

	all.data = &data;
	data.height = 1000;
	data.width =  1000;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.height, data.width, "Hello-world!");
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	which_fractol(&all);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
	(void)argc;
	(void)argv;
	return (0);
}
#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include "./minilibx_opengl_20191021/mlx.h"
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"
#include <math.h>
//REMOVE!!!!!!!!!!!!!!!!!!!!!!
#include <stdio.h>

typedef struct	s_data {
    void    *mlx;
    void    *mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_data;

typedef struct s_fractol {

}				t_fractol;

typedef struct   s_all {
    t_data      *data;
	t_fractol 	fractol;
	char		*type_fractol;
}               t_all;

int		create_trgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    which_fractol(t_all *all);
void       julia(t_all *all);
void    mandelbrot(t_all *all);

#endif
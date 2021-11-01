#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
// #include "./minilibx_opengl_20191021/mlx.h"
#include "./mlx/mlx.h"
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
	int		zoom;
}				t_data;

typedef struct s_fractol {
	double pr;
	double pi;
	double new_re;
	double old_re;
	double new_im;
	double old_im;
	double zoom;
	double move_x;
	double move_y;
	int	r;
	int g;
	int b;


}				t_fractol;

typedef struct   s_all {
    t_data      data;
	t_fractol 	fractol;
	char		*type_fractol;
}               t_all;

int		create_trgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    which_fractol(t_all *all);
void       julia(t_all *all);
void    mandelbrot(t_all *all);
int      close_window(int keycode, t_data *data);
void        exit_program(char *str);
void		set_structs(t_all *all);


////
void HSVtoRGB(float H, float S,float V, t_all *all);
int rgb_to_hsv(float r, float g, float b);

#endif
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

#define ESC 53
#define W_KEY 13
#define A_KEY 0
#define S_KEY 1
#define D_KEY 2

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
	char 	*str;
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
	double	c_re;
	double	c_im;
	int		diff_dist_y;
	int		diff_dist_x;
	int		new_mouse_x;
	int		new_mouse_y;
	int		old_mouse_x;
	int		old_mouse_y;
	int	r;
	int g;
	int b;
	char *color;
}				t_fractol;

typedef struct	s_julia {
	double		c_re;
	double 		c_im;
	double		new_re;
	double		old_re;
	double		new_im;
	double		old_im;
}				t_julia;

typedef struct   s_all {
    t_data      data;
	t_fractol 	fractol;
	t_julia		julia;
	char		*type;
}               t_all;

int		create_trgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    which_fractol(t_all *all);
void       julia(t_all *all);
int	    mandelbrot(t_all *all);
int      close_window(int keycode, t_all *all);
void        exit_program(char *str);
void		set_structs(t_all *all);
int 	mouse_press(int keycode, int x, int y, t_all *all);
void		colors(t_all *all, int i, int x, int y);


////
void HSVtoRGB(float H, float S,float V, t_all *all);
int rgb_to_hsv(float r, float g, float b);

#endif
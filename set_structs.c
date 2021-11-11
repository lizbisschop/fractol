#include "fractol.h"

void        set_structs(t_all *all)
{
   all->fractol.pr = 0;
   all->fractol.pi = 0;
   all->fractol.new_re = 0;
   all->fractol.new_im = 0;
   all->fractol.old_re = 0;
   all->fractol.old_im = 0;
   all->fractol.zoom = 1;
   all->fractol.move_x = -0.5;
   all->fractol.move_y = 0;
   all->data.zoom = 0;
   all->fractol.old_mouse_x = all->data.width / 2;
   all->fractol.old_mouse_y = all->data.height / 2;
   all->fractol.diff_dist_x = 0;
   all->fractol.diff_dist_y = 0;
   all->fractol.r = 20;
	all->fractol.g = 225;
	all->fractol.b = 0;
}
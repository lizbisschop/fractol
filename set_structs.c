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
}
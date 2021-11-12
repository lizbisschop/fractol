#include "fractol.h"

void    which_fractol(t_all *all)
{
	char	*line;

	// printf("Welcome to the fractol menu;\nThe fractols you could choose from are:\n-Julia\n-Mandelbrot\n");
	// while (1)
	// {
		// get_next_line(0, &line);
		if (ft_strncmp(all->type, "Julia", ft_strlen(all->type)) == 0 && ft_strlen(all->type) == 5)
		{
			// all->type_fractol = ft_strdup(all->type);
			// free(all->type);
			julia(all);
			// break ;
		}
		else if (ft_strncmp(all->type, "Mandelbrot", ft_strlen(all->type)) == 0 && ft_strlen(all->type) == 10)
		{
			// all->type_fractol = ft_strdup(all->type);
			// free(all->type);
			// mlx_loop_hook(all->data.mlx, &mandelbrot, all);
			mandelbrot(all);
			// break ;
		}
	// }
}
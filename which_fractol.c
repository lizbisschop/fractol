#include "fractol.h"

int		get_input(t_all *all)
{
	char *line;

	printf("hello\n");
	get_next_line(0, &line);
	if (ft_strncmp(line, "green", ft_strlen(line) == 0 && ft_strlen(line) == 5))
	{
		all->fractol.r = 20;
		all->fractol.g = 225;
		all->fractol.b = 0;
	}
	else if (ft_strncmp(line, "red", ft_strlen(line) == 0) && ft_strlen(line) == 3)
	{
		all->fractol.r = 225;
		all->fractol.g = 0;
		all->fractol.b = 0;
	}
	else
	{
		all->fractol.r = 225;
		all->fractol.g = 225;
		all->fractol.b = 225;		
	}
	return (0);
}

void    which_fractol(t_all *all)
{
	// char	*line;

	// printf("%s\n", all->fractol.color);
	// printf("%s\n", all->type);

		if (ft_strncmp(all->fractol.color, "green", ft_strlen(all->fractol.color)) == 0 && ft_strlen(all->fractol.color) == 5)
		{
			// printf("I am greeen\n")
			all->fractol.r = 20;
			all->fractol.g = 225;
			all->fractol.b = 0;
		}
		else if (ft_strncmp(all->fractol.color, "red", ft_strlen(all->fractol.color)) == 0 && ft_strlen(all->fractol.color) == 3)
		{
			// printf("Hello\n");
			all->fractol.r = 225;
			all->fractol.g = 0;
			all->fractol.b = 0;
		}
		else if (ft_strncmp(all->fractol.color, "purple", ft_strlen(all->fractol.color)) == 0 && ft_strlen(all->fractol.color) == 6)
		{
			// printf("Hello\n");
			all->fractol.r = 128;
			all->fractol.g = 0;
			all->fractol.b = 128;
		}
		else
		{
			all->fractol.r = 225;
			all->fractol.g = 225;
			all->fractol.b = 225;		
		}
		// mlx_loop_hook(all->data.mlx, &get_input, all);
		if (ft_strncmp(all->type, "julia", ft_strlen(all->type)) == 0 && ft_strlen(all->type) == 5)
		{
			// all->type_fractol = ft_strdup(all->type);
			// free(all->type);
			julia(all);
			// break ;
		}
		else if (ft_strncmp(all->type, "mandelbrot", ft_strlen(all->type)) == 0 && ft_strlen(all->type) == 10)
		{
			// all->type_fractol = ft_strdup(all->type);
			// free(all->type);
			// mlx_loop_hook(all->data.mlx, &mandelbrot, all);
			mandelbrot(all);
			// break ;
		}
	// }
}
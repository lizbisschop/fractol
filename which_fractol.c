#include "fractol.h"

void    which_fractol(t_all *all)
{
	// char	*line;

	// printf("Welcome to the fractol menu;\nThe fractols you could choose from are:\n-Julia\n-Mandelbrot\n");
	// while (1)
	// {
	// 	get_next_line(0, &line);
	// 	if (ft_strncmp(line, "Julia", ft_strlen(line)) == 0 && ft_strlen(line) == 5)
	// 	{
	// 		all->type_fractol = ft_strdup(line);
	// 		free(line);
			// julia(all);
	// 		break ;
	// 	}
	// 	else if (ft_strncmp(line, "mandelbrot", ft_strlen(line)) == 0 && ft_strlen(line) == 10)
	// 	{
	// 		all->type_fractol = ft_strdup(line);
	// 		free(line);
			mandelbrot(all);
	// 		break ;
	// 	}
	// 	else
	// 	{
	// 		printf("Wrong input, please try again...\n");
	// 		free(line);
	// 	}
	// }
}
#include "solong.h"

int	render(t_mlx *solong)
{
	if (!solong -> win.window)
		return (1);
	return (0);
}

t_image	inicialize_wall(t_mlx *solong)
{
	t_image	wall;

	wall.width = 32;
	wall.height = 32;
	wall.img = mlx_xpm_file_to_image(solong -> instance, "./wall_32.xpm", &wall.width, &wall.height);
	wall.x = 0;
	wall.y = 0;
	return wall;
}

t_image	inicialize_coletable(t_mlx *solong)
{
	t_image	coletable;

	coletable.width = 32;
	coletable.height = 32;
	coletable.img = mlx_xpm_file_to_image(solong -> instance, "./coletable01_32.xpm", &coletable.width, &coletable.height);
	coletable.x = 0;
	coletable.y = 0;
	return coletable;
}

void	putimages(t_mlx *solong)
{
	t_image	wall;
	t_image	coletable;

	wall = inicialize_wall(solong);
	coletable = inicialize_coletable(solong);
	mlx_put_image_to_window(solong -> instance, solong -> win.window, coletable.img, coletable.x, coletable.y);
	mlx_put_image_to_window(solong -> instance, solong -> win.window, wall.img, 200,  200);
}

void	so_long()
{
	t_mlx	solong;

	init_display(&solong);
	putimages(&solong);

	mlx_loop_hook(solong.instance, render, &solong);
	events_hook(&solong);
	mlx_loop(solong.instance);
	mlx_destroy_display(solong.instance);
	free(solong.instance);
}

int	main(void)
{
	so_long();

	return (0);
}

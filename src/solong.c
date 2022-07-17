#include "solong.h"

int	close_window(t_mlx *solong)
{
	if (solong->win.window)
	{
		mlx_destroy_window(solong->instance, solong->win.window);
	}
	return (0);
}

int	key_release(int key, t_mlx *solong)
{
	if (key == K_ESCAPE)
		close_window(solong);
	return (0);
}

int	render(t_mlx *solong)
{
	if (!solong -> win.window)
		return (1);
	return (0);
}

void	init_display(t_mlx *solong)
{
	solong -> instance = mlx_init();
	solong -> win.width = 320;
	solong -> win.heigh = 224;
	solong -> win.window = mlx_new_window(solong -> instance, solong -> win.width, solong -> win.heigh, "So_Long");
	solong -> status = 1;
}

void	events_hook(t_mlx *solong)
{
	mlx_hook(solong -> win.window, 17, 1<<24, close_window, solong);
	mlx_key_hook(solong -> win.window, key_release, solong);
}

t_image	inicialize_wall(t_mlx *solong)
{
	t_image	wall;

	wall.width = 32;
	wall.heigh = 32;
	wall.img = mlx_xpm_file_to_image(solong -> instance, "./wall_32.xpm", &wall.width, &wall.heigh);
	wall.x = 0;
	wall.y = 0;
	return wall;
}

t_image	inicialize_coletable(t_mlx *solong)
{
	t_image	coletable;

	coletable.width = 32;
	coletable.heigh = 32;
	coletable.img = mlx_xpm_file_to_image(solong -> instance, "./coletable01_32.xpm", &coletable.width, &coletable.heigh);
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

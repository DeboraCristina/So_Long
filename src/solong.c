#include "solong.h"

typedef struct	s_solong
{
	void	*init;
	void	*window;
	void	*image;
}	t_solong;

int	close_window(t_solong *solong)
{
	if (solong -> window)
	{
		mlx_destroy_window(solong -> init, solong -> window);
	}
	return (0);
}

int	key_release(int key, t_solong *solong)
{
	if (key == K_ESCAPE)
		close_window(solong);
	return (0);
}

int	render(t_solong *solong)
{
	if (!solong -> window)
		return (1);
	return (0);
}

void	putwall(t_solong solong)
{
	void	*img;
	void	*img02;

	int	x = 32;
	int	y = 32;
	img = mlx_xpm_file_to_image(solong.init, "./wall_32.xpm", &x, &y);
	img02 = mlx_xpm_file_to_image(solong.init, "./Enemy_Animation/Enemy_run_32_1.xpm", &x, &y);
	mlx_put_image_to_window(solong.init, solong.window, img02, (320 / 2), (224 / 2));

	int	w=0;
	while (w < 320)
	{
		mlx_put_image_to_window(solong.init, solong.window, img, w, 0);
		mlx_put_image_to_window(solong.init, solong.window, img, w, 192);
		w += 32;
	}

	int	h=32;
	while (h < 224)
	{
		mlx_put_image_to_window(solong.init, solong.window, img, 0, h);
		mlx_put_image_to_window(solong.init, solong.window, img, 288, h);
		h += 32;
	}
}

int	main(void)
{
	t_solong	solong;

	solong.init = mlx_init();
	solong.window = mlx_new_window(solong.init, 320, 224, "So_Long");

	putwall(solong);

	mlx_loop_hook(solong.init, render, &solong);
	mlx_hook(solong.window, 17, 1<<24, close_window, &solong);
	mlx_key_hook(solong.window, key_release, &solong);
	mlx_loop(solong.init);
	mlx_destroy_display(solong.init);
	free(solong.init);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct	s_window
{
	void	*mlx;
	void	*win;
}	t_window;

int	close(int k, t_window *window)
{
	if (!window)
	{
		printf("nada\n");
		return (0);
	}
	if (k == 'a')
	{
		mlx_clear_window(window -> mlx, window -> win);
 		mlx_destroy_window(window -> mlx, window -> win);
		printf("fecha\n");
	}
 	return (0);
}

int	hello()
{
	return (0);
}

int	main(void)
{
	t_window	window;

	printf("abre\n");
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 320, 224, "Hello, World!");
	mlx_loop_hook(window.mlx, hello, &window);
	mlx_key_hook(window.win, close, &window);
	mlx_loop(window.mlx);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
	printf("fim\n");
}


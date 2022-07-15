#include "so_long.h"

int	main(void)
{
	t_data	window;

	window.win.width = 320;
	window.win.heigh = 224;
	ft_printf("abre\n");
	window.mlx = mlx_init();
	window.win.win = mlx_new_window(window.mlx, window.win.width, window.win.heigh, "Hello, World!");
	mlx_loop_hook(window.mlx, update_window, &window);

	mlx_key_hook(window.win.win, ft_readInputKeys, &window);
	mlx_hook(window.win.win, 17, 1l<<24, ft_close_window, &window);

	mlx_loop(window.mlx);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
	ft_printf("fim\n");
}


#include <header.h>


int	update_window() //grafic or window???
{
	return (0);
}

int	main(void)
{
	t_data	window;

	ft_printf("abre\n");
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 320, 224, "Hello, World!");
	mlx_loop_hook(window.mlx, update_window, &window);

	mlx_key_hook(window.win, ft_readInputKeys, &window);

	mlx_loop(window.mlx);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
	ft_printf("fim\n");
}


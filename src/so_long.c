#include "so_long.h"


int	update_window() //grafic or window???
{
	return (0);
}

void	mouse_in()
{
	ft_printf("oi");
}

void	mouse_out()
{
	ft_printf("tchau");
}

int move_mouse(t_data *mlx)
{
	if (!mlx)
		return(0);
	ft_printf("olha eu aki");

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
	//mlx_hook(window.win, 6, 1l<<6, move_mouse, &window);
	mlx_hook(window.win, 17, 1l<<24, ft_close_window, &window);

	mlx_loop(window.mlx);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
	ft_printf("fim\n");
}


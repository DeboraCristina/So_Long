#include "so_long.h"

// int	ft_draw_rect(t_data *mlx, t_rect rect)
// {
// 	int	h;
// 	int	w;
// 
// 	if (!mlx.win)
// 		return(1);
// 	h = rect.y;
// 	while (h < (rect.y + rect.heigh))
// 	{
// 		w = rect.x;
// 		while (w < (rect.x + rect.width))
// 		{
// 			mlx_pixel_put(mlx.mlx, mlx.win, w, i, rect.color);
// 		}
// 	return (0);
// }

int	update_window(t_data *mlx) //grafic or window???
{
	if (!mlx)
		return (1);
	// ft_draw_rect(mlx, (t_rect){0, 0, 100, 50, GREEN});
	return (0);
}

int	main(void)
{
	t_data	window;
	int		x;
	int		y;

	x = 320;
	y = 224;
	ft_printf("abre\n");
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, x, y, "Hello, World!");
	mlx_loop_hook(window.mlx, update_window, &window);

	//mlx_pixel_put(window.mlx, window.win, x, y, GREEN);
	mlx_key_hook(window.win, ft_readInputKeys, &window);
	mlx_hook(window.win, 17, 1l<<24, ft_close_window, &window);

	mlx_loop(window.mlx);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
	ft_printf("fim\n");
}


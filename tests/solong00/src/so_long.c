#include "so_long.h"

int	main(void)
{
	t_data	window;
	void	*img;

	window.win.width = 320;
	window.win.heigh = 224;
	ft_printf("abre\n");
	window.mlx = mlx_init();
	window.win.win = mlx_new_window(window.mlx, window.win.width, window.win.heigh, "Hello, World!");
	mlx_loop_hook(window.mlx, update_window, &window);

	int	x=32;
	img = mlx_xpm_file_to_image(window.mlx, "./coletable01_32.png", &x, &x);
	if (!img)
		return (1);

	window.img.mlx_img = mlx_new_image(window.mlx, window.win.width, window.win.heigh);
	window.img.addr = mlx_get_data_addr(window.img.mlx_img, &window.img.bpp, &window.img.line_len, &window.img.endian);

	mlx_key_hook(window.win.win, ft_readInputKeys, &window); // captura as teclas
	mlx_hook(window.win.win, 17, 1l<<24, ft_close_window, &window); // fecha janela no X

	mlx_loop(window.mlx);
	mlx_destroy_image(window.mlx, window.img.mlx_img);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
	ft_printf("fim\n");
}


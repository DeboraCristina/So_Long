#include <stdio.h>
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*win;

	printf("ola\n");
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 200, "Hello, World!");
	if (!win)
		return (0);
	mlx_loop(mlx);
	return (0);
}


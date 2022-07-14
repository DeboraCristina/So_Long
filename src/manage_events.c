#include "so_long.h"

// key events
int	ft_readInputKeys(int key, t_data *mlx)
{
	if (!mlx)
		return (0); // erro
	if (key == K_ESCAPE)
	{
		ft_close_window(mlx);
		ft_printf("fecha\n");
	}
	else
		ft_printf("%d\n", key);
	return (0);
}

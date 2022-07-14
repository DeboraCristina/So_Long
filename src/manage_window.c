#include "so_long.h"

int	ft_close_window(t_data *window)
{
	if (window)
	{
		mlx_clear_window(window -> mlx, window -> win);
 		mlx_destroy_window(window -> mlx, window -> win);
	}
	return (0);
}

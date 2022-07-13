#include <so_long.h>

void	ft_close_window(t_data *window)
{
	if (window)
	{
		mlx_clear_window(window -> mlx, window -> win);
 		mlx_destroy_window(window -> mlx, window -> win);
	}
}

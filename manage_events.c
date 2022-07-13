#include <header.h>

// key events
int	ft_readInputKeys(int key, t_data *mlx)
{
	if (!mlx)
		return (NULL); // erro
	if (key == XK_Escape)
		ft_printf("fecha");
	return (0);
}

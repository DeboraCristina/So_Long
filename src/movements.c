#include "solong.h"

/*
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363
*/

int	ft_is_key_move(int key)
{
	if (key == K_W || key == K_S || key == k_A || key == K_D)
		return (1);
	if (key == K_UP || key == K_DOWN || key == k_LEFT || key == K_RIGHT)
		return (1);
	return (0);
}

void	move_player(int key, t_mlx *solong)
{
	if (key == k_W || key == k_UP)
		ft_printf("sobe\n");
}

#include "solong.h"

static void	end_game(int type)
{
	if (type == 3) // win
		ft_printf("Congratulations! You win!!\n");
	else
		ft_printf("Loooser!\n");
	ft_printf("Press ´ESC´ to exit.\n");
}

void	show_movements(int move)
{
	system("clear");
	ft_printf("Move: %d\n", move);
}

void	execute_movement(t_mlx *solong, t_image *player, t_image *tile)
{
	if (tile->id == 1)
		return ;
	show_movements(++solong->movements);
	if (tile->id == 0) // chão
		ft_swap_int(&tile->id, &player->id);
	else if (tile->id == 3 || tile->id == 5) // saida // inimigo
	{
		player->id = 0;
		solong->status = 0;
		end_game(tile->id);
	}
	else if (tile->id == 4) // coletavel
	{
		tile->id = player->id;
		player->id = 0;
	}
}

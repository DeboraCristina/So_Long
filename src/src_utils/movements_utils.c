/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:28:55 by desilva           #+#    #+#             */
/*   Updated: 2022/08/12 16:49:32 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_show_final_message(int type)
{
	if (type == 3)
		ft_printf("\e[1;92mCongratulations! You win!!\e[0m\n");
	else
		ft_printf("\e[1;93mCongratulations! You lose!\e[0m\n");
	ft_printf("\e[1;97mPress ´ESC´ to exit.\e[0m\n");
}

static void	ft_show_status(t_mlx *solong)
{
	ft_printf("\e[1;97mMove: %d\e[0m\n", solong->movements);
	ft_printf("\e[1;97mFruits: %d\e[0m\n", solong->collectibles);
}

static void	ft_end_game(t_mlx *solong, t_image *player, int tile_id)
{
	if (solong->collectibles == solong->total_collectibles || tile_id == 5)
	{
		player->id = 0;
		solong->status = 0;
	}
	else
		ft_printf("\e[1;93mYou need to collect all the fruits to get out.\e[0m\n");
}

void	execute_movement(t_mlx *solong, t_image *player, t_image *tile)
{
	system("clear");
	if (tile->id != 1)
		++solong->movements;
	if (tile->id == 0)
		ft_swap_int(&tile->id, &player->id);
	else if (tile->id == 3 || tile->id == 5)
		ft_end_game(solong, player, tile->id);
	else if (tile->id == 4)
	{
		tile->id = player->id;
		player->id = 0;
		++solong->collectibles;
	}
	ft_show_status(solong);
	if (!solong->status)
		ft_show_final_message(tile->id);
}

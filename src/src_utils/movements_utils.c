/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:28:55 by desilva           #+#    #+#             */
/*   Updated: 2022/08/08 19:04:45 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	end_game(int type)
{
	if (type == 3)
		ft_printf("\e[1;92mCongratulations! You win!!\e[0m\n");
	else
		ft_printf("\e[1;93mLoooser!\e[0m\n");
	ft_printf("\e[1;97mPress ´ESC´ to exit.\e[0m\n");
}

void	show_movements(int move)
{
	system("clear");
	ft_printf("\e[1;97mMove: %d\e[0m\n", move);
}

void	execute_movement(t_mlx *solong, t_image *player, t_image *tile)
{
	if (tile->id == 1)
		return ;
	show_movements(++solong->movements);
	if (tile->id == 0)
		ft_swap_int(&tile->id, &player->id);
	else if (tile->id == 3 || tile->id == 5)
	{
		player->id = 0;
		solong->status = 0;
		end_game(tile->id);
	}
	else if (tile->id == 4)
	{
		tile->id = player->id;
		player->id = 0;
	}
}

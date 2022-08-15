/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:28:55 by desilva           #+#    #+#             */
/*   Updated: 2022/08/14 06:31:07 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_end_game(t_mlx *solong, t_image *player, int tile_id)
{
	if (solong->collectibles == solong->total_collectibles || tile_id == 5)
	{
		player->id = 0;
		solong->status = 0;
	}
	else
		ft_printf("\e[1;93mYou can't leave yet.\e[0m\n");
}

void	execute_movement_player(t_mlx *solong, t_image *player, t_image *tile)
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

void	move_player(int key, t_mlx *solong)
{
	t_image	*player;

	if (!solong || !solong->status)
		return ;
	player = ft_find_objs_by_id(solong->objs, 2);
	if (key == K_W || key == K_UP)
		move(solong, player, 0, -SIZE);
	else if (key == K_S || key == K_DOWN)
		move(solong, player, 0, SIZE);
	else if (key == K_A || key == K_LEFT)
		move(solong, player, -SIZE, 0);
	else if (key == K_D || key == K_RIGHT)
		move(solong, player, SIZE, 0);
}

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

t_image	*ft_find_objs_by_id(t_list *objs, int id)
{
	t_image	*img;

	if (!objs)
		return ((t_image *) NULL);
	img = (t_image *) objs->content;
	if (img->id != id)
		img = ft_find_objs_by_id(objs->next, id);
	return (img);
}

t_image	*ft_find_objs_by_position(t_list *objs, int x, int y)
{
	t_image	*img;

	if (!objs)
		return ((t_image *) NULL);
	img = (t_image *) objs->content;
	if (img->y != y || img->x != x)
		img = ft_find_objs_by_position(objs->next, x, y);
	return (img);
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

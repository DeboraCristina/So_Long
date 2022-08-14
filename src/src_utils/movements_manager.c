/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:26:27 by desilva           #+#    #+#             */
/*   Updated: 2022/08/14 06:33:20 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move(t_mlx *solong, t_list *objs, int mx, int my)
{
	t_image	*player;
	t_image	*tile;

	if (!objs || !solong)
		return ;
	player = ft_find_objs_by_id(objs, 2);
	tile = ft_find_objs_by_position(objs, (player->x + mx), (player->y + my));
	execute_movement(solong, player, tile);
}

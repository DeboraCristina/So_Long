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

void	execute_movement(t_mlx *solong, t_image *entity, t_image *tile)
{
	if (entity->id == 2)
		execute_movement_player(solong, entity, tile);
	else if (entity->id == 5)
		execute_movement_enemy(entity, tile);
}

void	move(t_mlx *solong, t_image *ent, int mx, int my)
{
	t_image	*tile;

	if (!solong->objs || !solong)
		return ;
	tile = ft_find_objs_by_position(solong->objs, (ent->x + mx), (ent->y + my));
	execute_movement(solong, ent, tile);
}

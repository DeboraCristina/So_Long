/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:26:27 by desilva           #+#    #+#             */
/*   Updated: 2022/08/12 17:03:28 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static t_image	*ft_find_objs_by_id(t_list *objs, int id)
{
	t_image	*img;

	if (!objs)
		return ((t_image *) NULL);
	img = (t_image *) objs->content;
	while (img->id != id && objs)
	{
		objs = objs->next;
		img = (t_image *) objs->content;
	}
	if (!objs)
		return ((t_image *) NULL);
	return (img);
}

static t_image	*ft_find_objs_by_position(t_list *objs, int x, int y)
{
	t_image	*img;

	if (!objs)
		return ((t_image *) NULL);
	img = (t_image *) objs->content;
	if (img->y != y || img->x != x)
		img = ft_find_objs_by_position(objs->next, x, y);
	return (img);
}

# define DEBUG 1

void	move(t_mlx *solong, t_list *objs, int mx, int my)
{
	t_image	*player;
	t_image	*tile;
	t_list	*temp;

	if (!objs || !solong)
		return ;
	temp = objs;
#if DEBUG == 0
	int		contencao;
	player = ft_find_objs_by_id(temp, 2);
	contencao = 0;
	while (player && contencao <= 10)
	{
		player = ft_find_objs_by_id(temp, 2);
		tile = ft_find_objs_by_position(objs, (player->x + mx), (player->y + my));
		execute_movement(solong, player, tile);
		contencao ++;
	}
#else
	player = ft_find_objs_by_id(temp, 2);
	tile = ft_find_objs_by_position(objs, (player->x + mx), (player->y + my));
	execute_movement(solong, player, tile);
#endif
}

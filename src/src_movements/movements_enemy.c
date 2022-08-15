/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:56:37 by desilva           #+#    #+#             */
/*   Updated: 2022/08/15 03:56:40 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static t_list	*ft_get_enemies(t_list *objs)
{
	t_list	*enemies_lst;
	t_image	*entity;
	int		c;

	c = 0;
	while (objs)
	{
		entity = (t_image *) objs->content;
		if (entity->id == 5)
		{
			if (c == 0)
				enemies_lst = ft_lstnew(entity);
			else
				ft_lstadd_back(&enemies_lst, ft_lstnew(entity));
			c++;
		}
		objs = objs->next;
	}
	return (enemies_lst);
}

void	execute_movement_enemy(t_mlx *solong, t_image *enemy, t_image *tile)
{
	if (!solong->status)
		return ;
	if (tile->id == 0)
	{
		ft_swap_int(&tile->id, &enemy->id);
		ft_swap_int(&tile->dir, &enemy->dir);
	}
	if (tile->id == 2)
		ft_end_game(solong, tile, enemy->id);
	else
		enemy->dir = enemy->dir * (-1);
	if (!solong->status)
		ft_show_final_message(enemy->id);
}

void	move_enemy(t_mlx *solong)
{
	t_list	*temp_objs;
	t_list	*enemies_lst;
	t_list	*temp;
	t_image	*enemy;

	if (!solong)
		return ;
	temp_objs = solong->objs;
	enemies_lst = ft_get_enemies(temp_objs);
	while (enemies_lst)
	{
		enemy = (t_image *) enemies_lst->content;
		move(solong, enemy, 0, SIZE * (enemy->dir));
		temp = enemies_lst;
		enemies_lst = enemies_lst->next;
		free(temp);
	}
}

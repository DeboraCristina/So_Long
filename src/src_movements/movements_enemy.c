/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:53:56 by desilva           #+#    #+#             */
/*   Updated: 2022/08/18 15:53:59 by desilva          ###   ########.fr       */
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

void	execute_movement_enemy(t_image *enemy, t_image *tile)
{
	if (tile->id == 0)
	{
		ft_swap_int(&tile->id, &enemy->id);
		ft_swap_int(&tile->dir, &enemy->dir);
	}
	else
		enemy->dir = enemy->dir * (-1);
}

void	move_enemy(t_mlx *solong)
{
	t_list	*temp_objs;
	t_list	*enemies_lst;
	t_list	*temp;
	t_image	*enemy;

	if (!solong || !solong->enemies)
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

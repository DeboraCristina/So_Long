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
		ft_printf("anda\n");
	}
	else
	{
		enemy->dir = enemy->dir * (-1);
		ft_printf("não anda\n");
	}
	ft_printf("X: %d | Y: %d | dir: %d\n", enemy->x, enemy->y, enemy->dir);
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
	ft_printf("entrou\n");
	while (enemies_lst)
	{
		enemy = (t_image *) enemies_lst->content;
		move(solong, enemy, 0, SIZE * (enemy->dir));
		temp = enemies_lst;
		enemies_lst = enemies_lst->next;
		free(temp);
	}
	ft_printf("saiu\n");
}

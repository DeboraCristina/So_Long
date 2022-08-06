#include "solong.h"

static t_image	*ft_find_objs_by_id(t_list *objs, int id)
{
	t_image	*img;

	if (!objs)
		return (t_image *)NULL;
	img = (t_image *) objs->content;
	if (img->id != id)
		img = ft_find_objs_by_id(objs->next, id);
	return (img);
}

static t_image	*ft_find_objs_by_position(t_list *objs, int x, int y)
{
	t_image	*img;

	if (!objs)
		return (t_image *)NULL;
	img = (t_image *) objs->content;
	if (img->y != y || img->x != x)
		img = ft_find_objs_by_position(objs->next, x, y);
	return (img);
}

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

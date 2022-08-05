#include "solong.h"

static t_image	*ft_find_objs_by_name(t_list *objs, char *elem)
{
	t_image	*img;

	img = (t_image *) objs->content;
	if (ft_strcmp(img->name, elem))
		img = ft_find_objs_by_name(objs->next, elem);
	return (img);
}

static t_image	*ft_find_objs_by_position(t_list *objs, int x, int y)
{
	t_image	*img;

	img = (t_image *) objs->content;
	if (img->y != y || img->x != x)
		img = ft_find_objs_by_position(objs->next, x, y);
	return (img);
}

void	move(t_list *objs, int mx, int my)
{
	char	*old_name;
	t_image	*player;
	t_image	*tile;
	
	if (!objs)
		return ;
	player = ft_find_objs_by_name(objs, "2");
	tile = ft_find_objs_by_position(objs, (player->x + mx), (player->y + my));
	if (ft_strcmp(tile->name, "1"))
	{
		old_name = tile->name;
		tile->name = player->name;
		player->name = old_name;
	}
}

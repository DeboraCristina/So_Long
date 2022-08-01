#include "solong.h"

char	*get_name(char c)
{
	char	*name;

	name = NULL;
	if (c == '1')
		name = "1";
	else if (c == 'P')
		name = "2";
	else if (c == 'E')
		name = "3";
	else if (c == 'C')
		name = "4";
	else if (c == 'D')
		name = "5";
	else
		name = "0";
	return (name);
}

t_list	*gen_objects(t_map *p_map)
{
	t_list	*objs;
	t_image *img;
	int		c;

	c = 0;
	while (p_map->mapping[c])
	{
		img = (t_image *) malloc(sizeof(t_image));
		img->x = ((c % (p_map->width - 1)) * 32);
		img->y = ((c / (p_map->width - 1)) * 32);
		img->name = get_name(p_map->mapping[c]);
		if (c == 0)
			objs = ft_lstnew(img);
		else
			ft_lstadd_back(&objs, ft_lstnew(img));
		c++;
	}
	return (objs);
}

t_list	*gen_images(void *p_mlx)
{
	t_list	*xpm;
	int		size;

	size = SIZE;
	xpm = ft_lstnew(XMP_TO_IMG(p_mlx, SPACE, &size, &size));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, WALL, &size, &size)));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, PLAYER, &size, &size)));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, EXIT, &size, &size)));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, COLLECT, &size, &size)));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, DEVIL, &size, &size)));
	return (xpm);
}

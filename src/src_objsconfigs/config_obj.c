#include "solong.h"

char	*get_name(char c)
{
	char	*name;

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
	return (name);
}

t_list	*gen_objects(t_map *p_map)
{
	t_list	*objs;
	t_image *img;
	int		c;

	objs = ft_lstnew((void *) 0);
	c = 0;
	while (p_map->mapping[c])
	{
		if (p_map->mapping[c] != 0)
		{
			img = (t_image *) malloc(sizeof(t_image));
			img->x = ((c % 10) * 32);
			img->y = ((c / (p_map->width - 1)) * 32);
			img->name = get_name(p_map->mapping[c]);
			ft_lstadd_back(&objs, ft_lstnew(img));
		}
		c++;
	}
	return (objs);
}

t_list	*gen_images(void *p_mlx)
{
	t_list	*xpm;
	int		size;

	xpm = ft_lstnew((void *) 0);
	size = SIZE;
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, SPACE, &size, &size)));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, WALL, &size, &size)));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, PLAYER, &size, &size)));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, EXIT, &size, &size)));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, COLLECT, &size, &size)));
	ft_lstadd_back(&xpm, ft_lstnew(XMP_TO_IMG(p_mlx, DEVIL, &size, &size)));
	return (xpm);
}

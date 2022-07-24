#include "solong.h"
#include "map_manager.h"

int	check_map(char *name)
{
	char	*error;

	error = NULL;
	if (!check_map_name(name))
	{
		error = "name";
	}
	else if (!valid_map_elements(name))
	{
		error = "format";
	}
	else if (!minimum_elements(name))
	{
		error = "minimum elements";
	}
	if (error)
	{
		ft_printf("Error! -- %s --\n", error);
		return (0);
	}
	return (1);
}

t_map	map_generator(char *name)
{
	t_map	v_map;
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	line = gnl(fd);
	v_map.mapping = ft_calloc(row_counter(name) * ft_strlen(line), 1);
	v_map.height = row_counter(name);
	gen_maplst(name, &v_map);
	free(line);
	close(fd);
	return (v_map);
}

void	gen_objects(t_mlx *mlx, t_objlk *objs, t_map *p_map)
{
	t_objlk	*obj;
	t_image	*img;
	char	*name;
	int		count;

	if (!mlx || !p_map || !objs)
		return ;
	count = 0;
	while (p_map->mapping[count])
	{
		img = (t_image *) malloc(sizeof(t_image));
		img->size = 32;
		if (p_map->mapping[count] == '1')
			name = "wall";
		else if (p_map->mapping[count] == 'P')
			name = "player";
		else if (p_map->mapping[count] == 'C')
			name = "coletable";
		else if (p_map->mapping[count] == 'E')
			name = "exit";
		else if (p_map->mapping[count] == 'D')
			name = "devil";
		else
			name = "null";
		img->x = ((count % 10) * 32);
		img->y = ((count / (p_map->width - 1)) * 32);
		img->img = name;
		obj = ft_newobj(img);
		ft_objadd_back(&objs, obj);
		count++;
	}
}

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
	t_image	*ob;
	char	*nm;
	char	elem;
	int		count;

	if (!mlx)
		return ;
	count = 0;
	ob = (t_image *) malloc(sizeof(t_image));
	ob->size = 32;
	while (p_map->mapping[count])
	{
		elem = p_map->mapping[count];
		if (elem == '1')
			nm = "wall";
		else if (elem == 'P')
			nm = "player";
		else if (elem == 'C')
			nm = "coletable";
		else if (elem == 'E')
			nm = "exit";
		else if (elem == 'D')
			nm = "devil";
		if (elem != '0')
		{
			ob->x = count * 32;
			ob->y = (count / p_map->width) * 32;
			ob->img = nm;
			ft_objadd_back(&objs, ft_newobj(&ob));
		}
		count ++;
	}
}

//		else
//		{
//			ob.x = count * 32;
//			ob.y = (count / p_map->width) * 32;
//			ob.img = mlx_xpm_file_to_image(mlx->init, nm, &ob.size, &ob.size);
//			ft_lstadd_back(&objs, ft_lstnew(&ob));
//		}

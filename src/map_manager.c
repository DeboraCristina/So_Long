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

t_list	*get_objects(t_mlx *mlx, t_map *p_map)
{
	void	adresses[5];
	t_list	*objs;

	objs = ft_lstnew((void *) 0);
	ft_bzero(adresses, 5);
	gen_adress(mlx->init, p_map->mapping, adresses);
	gen_objects(adresses, objs);
	return (objs);
}

void	get_elements_map(char *str_map, char *elements)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (str_map[c])
	{
		if (!ft_strchr(elements, str_map[c]))
		{
			elements[i] = str_map[c];
			i++;
		}
		c++;
	}
}

void	gen_adress(void *mlx_ptr, char *str_map, void *adresses)
{
	int		i;
	int		size;
	char	elements[5];

	i = 0;
	size = SIZE;
	ft_bzero(elements, 5);
	get_elements_map(str_map, elements);
	while (elements[i])
	{
		adresses[i] = mlx_xpm_file_to_image(mlx_ptr, get_name(elements[i]);, &size, &size);
		i++;
	}
}

void	gen_objects(void *adresses, t_list	*objs, char *str_map)
{
	t_image	*img;
	char	elements[5];
	int		c;

	c = 0;
	ft_bzero(elements, 5);
	get_elements_map(str_map, elements);
	while (str_map[c]) // 11111 1PCE1 11111
	{
		img = (t_image *) malloc(sizeof(t_image));
		img->x = ((count % 10) * 32);
		img->y = ((count / (p_map->width - 1)) * 32);
		img->img = 
	}
}

/*void	gen_objects(t_mlx *mlx, t_objlk *objs, t_map *p_map)
{
	t_objlk	*obj;
	
	char	*name;
	int		count;
	void	*v;

	if (!mlx || !p_map || !objs)
	{
		if (!p_map)
			ft_printf("no map\n");
		if (!objs)
			ft_printf("no obj\n");
		if (!mlx)
			ft_printf("no mlx\n");
		ft_printf("nothing\n");
		return ;
	}
	count = 0;
	while (p_map->mapping[count])
	{
		
		img->size = 32;
		name = get_name(p_map->mapping[count]);
		v = mlx_xpm_file_to_image(mlx->init, name, &img->size, &img->size);
		if (!v)
			return ;
		img->img = name;
		obj = ft_newobj(img);
		ft_objadd_back(&objs, obj);
		count++;
	}
}
*/
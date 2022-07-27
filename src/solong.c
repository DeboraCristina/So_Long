#include "solong.h"

void	show (t_objlk *lst)
{
	if (!lst)
	{
		ft_printf("nada\n");
		return ;
	}
	while (lst)
	{
		if (lst->presets)
		{
			ft_printf("|x = %d- y = %d|\t", lst->presets->x, lst->presets->y);
			ft_printf("|%s|\n", lst->presets->img);
		}
		lst = lst->next;
	}
}

int	render(t_mlx *solong, t_objlk *objs)
{
	if (!solong)
		return (1);
	show(objs);
	return (0);
}

void	scene_building(t_objlk *objs, t_mlx *solong)
{
	while (objs)
	{
		mlx_put_image_to_window(solong->init, solong->win.window, objs->presets->img, objs->presets->x, objs->presets->y);
		objs = objs->next;
	}
}

void	so_long(t_map *p_map)
{
	t_mlx solong;
	t_objlk	*objs;

	objs = ft_newobj((void *) 0);
	init_display(&solong);
	gen_objects(&solong, objs, p_map);

	//scene_building(objs, &solong);
	mlx_loop_hook(solong.init, render, &solong);
	events_hook(&solong);
	show(objs);
	mlx_loop(solong.init);
	mlx_destroy_display(solong.init);
	ft_objclear(&solong, objs);
	free(solong.init);
}

int	main(int argc, char **argv)
{
	t_map	v_map;

	if (argc < 2)
		return (1);
	if (!check_map(argv[1]))
		return (1);
	v_map = map_generator(argv[1]);
	so_long(&v_map );
	free(v_map.mapping);
	return (0);
}

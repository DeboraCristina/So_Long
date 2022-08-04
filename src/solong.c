#include "solong.h"

t_image	*find_player(t_list *objs)
{
	t_image	*img;

	img = (t_image *) objs->content;
	if (ft_strcmp(img->name, "2"))
		img = find_player(objs->next);
	return (img);
}

int	render(t_mlx *solong)
{
	// t_image	*img;

	if (!solong)
		return (1);
	//img = find_player(solong->objs);
	//img->x = img->x + 1;
	//ft_printf("|%d|\n", img->x);
	put_background(*solong);
	put_walls(*solong);
	put_player(*solong);
	put_exit(*solong);
	put_collectable(*solong);
	put_enemy(*solong);
	return (0);
}

int	expose(t_mlx *solong)
{
	if (!solong)
		return (1);
	return (0);
}

void	so_long(t_map *p_map)
{
	t_mlx	solong;

	init_display(&solong, p_map);
	solong.objs = gen_objects(p_map);
	solong.xpm_images = gen_images(solong.init);
	mlx_loop_hook(solong.init, render, &solong);
	events_hook(&solong);
	mlx_loop(solong.init);
	ft_lstclear(&solong.objs, free);
	ft_destroy_images(solong.init, solong.xpm_images);
	mlx_destroy_display(solong.init);
	free(solong.init);
}

int	main(int argc, char **argv)
{
	t_map	v_map;

	
	if (argc < 2)
	{
		ft_printf("Cade o mapa jamanta?!\n");
		return (1);
	}
	if (!check_map(argv[1]))
		return (1);
	v_map = map_generator(argv[1]);
	so_long(&v_map);
	free(v_map.mapping);
	return (0);
}

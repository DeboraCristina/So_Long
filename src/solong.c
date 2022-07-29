#include "solong.h"

/*void	show (t_list *lst)
{
	if (!lst)
	{
		ft_printf("nada\n");
		return ;
	}
	while (lst)
	{
		if (lst->content)
		{
			ft_printf("|x = %d- y = %d|\t", lst->content->x, lst->content->y);
			ft_printf("|%s|\n", lst->content->img);
		}
		lst = lst->next;
	}
}*/

int	render(t_mlx *solong)
{
	if (!solong)
		return (1);
	return (0);
}

void	so_long(t_map *p_map)
{
	t_mlx	solong;
	t_list	*objs;
	t_list	*xpm_images;

	init_display(&solong);
	objs = gen_objects(p_map);
	xpm_images = gen_images(&solong);
	mlx_loop_hook(solong.init, render, &solong);
	events_hook(&solong);
	if (!objs  || !xpm_images )
		return ;
	mlx_loop(solong.init);
	mlx_destroy_display(solong.init);
	// ft_objclear(&solong, objs);
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

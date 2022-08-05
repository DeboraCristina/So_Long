#include "solong.h"

void	so_long(t_map *p_map)
{
	t_mlx	solong;

	init_display(&solong, p_map);
	solong.objs = gen_objects(p_map);
	solong.xpm_images = gen_images(solong.init);
	mlx_loop_hook(solong.init, render, &solong);
	events_hook(&solong);
	mlx_loop(solong.init);
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

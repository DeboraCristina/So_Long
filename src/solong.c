#include "solong.h"

int	main(int argc, char **argv)
{
	t_objlk	*objs;
	t_map	v_map;
	t_mlx mlx;

	if (argc < 2)
		return (1);
	if (!check_map(argv[1]))
		return (1);
	objs = (t_objlk *) NULL;
	mlx.init = mlx_init();
	v_map = map_generator(argv[1]);
	gen_objects(&mlx, objs, &v_map);
	//so_long();

	mlx_destroy_display(mlx.init);
	ft_objclear(objs);
	free(v_map.mapping);
	free(mlx.init);
	return (0);
}

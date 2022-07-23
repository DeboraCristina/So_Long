#include "solong.h"

void	show (t_objlk *lst)
{
	while (lst)
	{
		if (lst->presets)
		{
			ft_printf("|%d|\n", lst->presets->x);
			ft_printf("|%s|\n", lst->presets->img);
		}
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_objlk	objs;
	t_map	v_map;
	t_mlx mlx;

	if (argc < 2)
		return (1);
	if (!check_map(argv[1]))
		return (1);
	mlx.init = mlx_init();
	mlx.win.window = mlx_new_window(mlx.init, 320, 224, "solong");
	v_map = map_generator(argv[1]);
	gen_objects(&mlx, &objs, &v_map);
	show(&objs);
	ft_printf("aki\n");
	//so_long();

	close_window(&mlx);
	mlx_destroy_display(mlx.init);
	free(mlx.init);
	return (0);
}

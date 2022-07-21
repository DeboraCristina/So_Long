#include "solong.h"

void	show (t_list *lst)
{
	while (lst->next)
	{
		ft_printf("|%d|\n", lst->content.x);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	objs;
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
	//so_long();

	mlx_destroy_display(mlx.init);
	free(mlx.init);
	return (0);
}

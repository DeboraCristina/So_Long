/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:17:54 by desilva           #+#    #+#             */
/*   Updated: 2022/08/08 19:04:58 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	so_long(t_map *p_map)
{
	t_mlx	solong;

	if (init_display(&solong, p_map))
		return ;
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

	system("clear");
	if (argc < 2)
	{
		ft_printf("\e[1;91mError:\e[0;91mNo arguments.\n");
		return (1);
	}
	check_map(argv[1]);
	v_map = map_generator(argv[1]);
	ft_printf("\e[1;97mMove: 0\e[0m\n");
	so_long(&v_map);
	free(v_map.mapping);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:17:40 by desilva           #+#    #+#             */
/*   Updated: 2022/08/12 17:10:34 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ft_count_collectibles(char *mapping)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (mapping && mapping[i])
	{
		if (mapping[i] == 'C')
			c++;
		i++;
	}
	return (c);
}

int	init_display(t_mlx *solong, t_map *p_map)
{
	int	width;
	int	height;

	width = (p_map->width - 1) * 32;
	height = p_map->height * 32;
	solong -> init = mlx_init();
	if (!solong -> init)
		return (print_error(INIT));
	solong -> win.width = width;
	solong -> win.height = height;
	solong -> win.window = mlx_new_window(solong -> init, solong -> win.width, \
		solong -> win.height, \
		"So_Long");
	if (!solong -> win.window)
	{
		free(solong->init);
		return (print_error(INIT));
	}
	solong -> status = 1;
	solong -> movements = 0;
	solong -> time = 0;
	solong -> collectibles = 0;
	solong -> total_collectibles = ft_count_collectibles(p_map->mapping);
	return (0);
}

void	events_hook(t_mlx *solong)
{
	mlx_hook(solong -> win.window, 17, 1 << 24, close_window, solong);
	mlx_key_hook(solong -> win.window, key_release, solong);
}

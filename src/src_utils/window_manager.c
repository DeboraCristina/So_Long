/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:17:40 by desilva           #+#    #+#             */
/*   Updated: 2022/08/18 15:51:51 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ft_count_entities(char *mapping, char ent)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (mapping && mapping[i])
	{
		if (mapping[i] == ent)
			c++;
		i++;
	}
	return (c);
}

void	init_variables(t_mlx *solong, t_map *p_map)
{
	solong -> status = 1;
	solong -> movements = 0;
	solong -> time = 0;
	solong -> collectibles = 0;
	solong -> total_collectibles = ft_count_entities(p_map->mapping, 'C');
	solong -> enemies = ft_count_entities(p_map->mapping, 'D');
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
	init_variables(solong, p_map);
	return (0);
}

void	events_hook(t_mlx *solong)
{
	mlx_hook(solong -> win.window, 17, 1 << 24, close_window, solong);
	mlx_key_hook(solong -> win.window, key_release, solong);
}

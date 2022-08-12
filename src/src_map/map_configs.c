/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_configs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:39:25 by desilva           #+#    #+#             */
/*   Updated: 2022/08/12 17:19:21 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "map_manager.h"

void	gen_maplst(char *name, t_map *p_map)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(name, O_RDONLY);
	line = gnl(fd);
	while (line)
	{
		count = 0;
		while (line[count])
		{
			if (line[count] != '\n')
				p_map->mapping[ft_strlen(p_map->mapping)] = line[count];
			count ++;
		}
		free(line);
		line = gnl(fd);
	}
	close(fd);
}

void	get_map_width(char *name, t_map *p_map)
{
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	line = gnl(fd);
	p_map->width = ft_strlen(line);
	free(line);
	close(fd);
}

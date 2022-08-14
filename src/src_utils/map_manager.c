/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:26:33 by desilva           #+#    #+#             */
/*   Updated: 2022/08/13 03:57:50 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "map_manager.h"

int	check_map(char *name)
{
	int	error;

	error = 0;
	if (!check_map_name(name))
		error = ft_printf("\e[1;91mError\nInvalid map name.\n");
	else if (!valid_map_elements(name))
		error = ft_printf("\e[1;91mError\nInvalid map format.\n");
	else if (!minimum_elements(name))
		error = ft_printf("\e[1;91mError\nMinimum requirements are missing.\n");
	if (error)
		exit(1);
	return (0);
}

t_map	map_generator(char *name)
{
	t_map	v_map;
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	line = gnl(fd);
	v_map.mapping = ft_calloc(row_counter(name) * ft_strlen(line), 1);
	if (!v_map.mapping)
		put_error(MALLOC);
	v_map.height = row_counter(name);
	v_map.player = 0;
	gen_maplst(name, &v_map);
	get_map_width(name, &v_map);
	free(line);
	close(fd);
	return (v_map);
}

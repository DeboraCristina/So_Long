/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:14:57 by desilva           #+#    #+#             */
/*   Updated: 2022/07/19 17:00:29 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "verify_map_utils.h"

int	check_map(char *name)
{
	char	*error;

	error = NULL;
	if (!check_map_name(name))
	{
		error = "name";
	}
	else if (!valid_map_elements(name))
	{
		error = "format";
	}
	else if (!minimum_elements(name))
	{
		error = "minimum elements";
	}
	if (error)
	{
		ft_printf("Error! -- %s --\n", error);
		return (0);
	}
	return (1);
}

t_map	map_genarator(char *name)
{
	t_map	v_map;
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	line = gnl(fd);
	v_map.maping = ft_calloc(row_counter(name) * ft_strlen(line), 1);
	v_map.height = row_counter(name);
	gen_maplst(name, &v_map);
	ft_printf("-- H = %d | W = %d --\n", v_map.height, v_map.width);
	ft_printf("-- %s --\n", v_map.maping);
	free(line);
	close(fd);
	return (v_map);
}

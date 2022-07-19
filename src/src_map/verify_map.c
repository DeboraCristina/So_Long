/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:14:57 by desilva           #+#    #+#             */
/*   Updated: 2022/07/19 17:00:46 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "verify_map_utils.h"

int	valid_map_elements(char *name)
{
	int		filedescriptor;
	char	*line;
	int		count;
	int		last_line;

	count = 0;
	filedescriptor = open(name, O_RDONLY);
	last_line = row_counter(name);
	if (filedescriptor < 0)
		return (0);
	line = gnl(filedescriptor);
	if (!line)
		return (0);
	while (line)
	{
		if (!valid_elements(count, last_line, line))
			return (0);
		free(line);
		line = gnl(filedescriptor);
		count++;
	}
	close(filedescriptor);
	return (1);
}

int	minimum_elements(char *name)
{
	int		minimum[3];

	minimum[0] = 0;
	minimum[1] = 0;
	minimum[2] = 0;
	gen_minimuns(minimum, name);
	if (!minimum[0] || !minimum[1] || !minimum[2])
		return (0);
	return (1);
}

int	check_map_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 5 || ft_strcmp((name + (len - 4)), ".ber"))
		return (0);
	return (1);
}

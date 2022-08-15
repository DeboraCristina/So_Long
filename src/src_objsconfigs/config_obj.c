/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:28:01 by desilva           #+#    #+#             */
/*   Updated: 2022/08/13 03:56:31 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	get_id(char c, t_map *p_map)
{
	int	id;

	id = 0;
	if (c == '1')
		id = 1;
	else if (c == 'P')
	{
		if (!p_map->player)
		{
			id = 2;
			p_map->player = 1;
		}
		else
			id = 0;
	}
	else if (c == 'E')
		id = 3;
	else if (c == 'C')
		id = 4;
	else if (c == 'D')
		id = 5;
	else
		id = 0;
	return (id);
}

t_list	*gen_objects(t_map *p_map)
{
	t_list	*objs;
	t_image	*img;
	int		c;

	c = 0;
	while (p_map->mapping[c])
	{
		img = (t_image *) malloc(sizeof(t_image));
		if (!img)
			put_error(MALLOC);
		img->x = ((c % (p_map->width - 1)) * 32);
		img->y = ((c / (p_map->width - 1)) * 32);
		img->id = get_id(p_map->mapping[c], p_map);
		img->dir = 1;
		if (c == 0)
			objs = ft_lstnew(img);
		else
			ft_lstadd_back(&objs, ft_lstnew(img));
		c++;
	}
	return (objs);
}

t_list	*gen_images(void *p_mlx)
{
	t_list	*xpm_lst;
	void	*xpm_img;
	int		size;

	size = SIZE;
	xpm_img = mlx_xpm_file_to_image(p_mlx, SPACE, &size, &size);
	xpm_lst = ft_lstnew(xpm_img);
	xpm_img = mlx_xpm_file_to_image(p_mlx, WALL, &size, &size);
	ft_lstadd_back(&xpm_lst, ft_lstnew(xpm_img));
	xpm_img = mlx_xpm_file_to_image(p_mlx, PLAYER, &size, &size);
	ft_lstadd_back(&xpm_lst, ft_lstnew(xpm_img));
	xpm_img = mlx_xpm_file_to_image(p_mlx, EXIT, &size, &size);
	ft_lstadd_back(&xpm_lst, ft_lstnew(xpm_img));
	xpm_img = mlx_xpm_file_to_image(p_mlx, COLLECT, &size, &size);
	ft_lstadd_back(&xpm_lst, ft_lstnew(xpm_img));
	xpm_img = mlx_xpm_file_to_image(p_mlx, DEVIL, &size, &size);
	ft_lstadd_back(&xpm_lst, ft_lstnew(xpm_img));
	return (xpm_lst);
}

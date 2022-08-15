/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:26:03 by desilva           #+#    #+#             */
/*   Updated: 2022/08/14 06:27:47 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	*ft_find_image(t_list *imgs, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		imgs = imgs->next;
		i ++;
	}
	return (imgs->content);
}

static void	put_images(t_list *objs, t_mlx *solong)
{
	t_image	*img;
	int		x;
	int		y;
	void	*elem;

	if (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		elem = ft_find_image(solong->xpm_images, img->id);
		put_images(objs->next, solong);
		mlx_put_image_to_window(solong->init, solong->win.window, elem, x, y);
	}
}

int	render(t_mlx *solong)
{
	if (!solong)
		return (1);
	if ((solong -> time ++) / 1000 && solong -> status)
	{
		move_enemy(solong);
		solong -> time = 0;
	}
	put_images(solong->objs, solong);
	return (0);
}

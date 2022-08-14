/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:26:36 by desilva           #+#    #+#             */
/*   Updated: 2022/08/08 09:26:36 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	close_window(t_mlx *solong)
{
	if (solong->win.window)
	{
		ft_lstclear(&solong->objs, free);
		ft_destroy_images(solong->init, solong->xpm_images);
		mlx_destroy_window(solong->init, solong->win.window);
	}
	return (0);
}

int	key_release(int key, t_mlx *solong)
{
	if (key == K_ESCAPE)
		close_window(solong);
	else if (key == K_W || key == K_S || key == K_A || key == K_D)
		move_player(key, solong);
	else if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
		move_player(key, solong);
	return (0);
}

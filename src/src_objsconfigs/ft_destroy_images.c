/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:28:02 by desilva           #+#    #+#             */
/*   Updated: 2022/08/08 09:28:02 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_destroy_images(void *p_mlx, t_list *lst)
{
	if (lst)
	{
		ft_destroy_images(p_mlx, lst->next);
		mlx_destroy_image(p_mlx, lst->content);
		free(lst);
	}
}

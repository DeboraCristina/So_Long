/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 06:28:49 by desilva           #+#    #+#             */
/*   Updated: 2022/08/14 06:32:10 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_show_final_message(int type)
{
	if (type == 3)
		ft_printf("\e[1;92mCongratulations! You win!!\e[0m\n");
	else
		ft_printf("\e[1;93mCongratulations! You lose!\e[0m\n");
}

void	ft_show_status(t_mlx *solong)
{
	ft_printf("\e[1;97mMove: %d\e[0m\n", solong->movements);
	ft_printf("\e[1;97mFruits: %d\e[0m\n", solong->collectibles);
}

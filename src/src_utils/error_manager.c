/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:14:42 by desilva           #+#    #+#             */
/*   Updated: 2022/08/11 16:14:45 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	print_error(int error)
{
	if (error == MALLOC)
		ft_printf("\e[1;91mError:Malloc error.\n");
	if (error == INIT)
		ft_printf("\e[1;91mError:Startup error.\n");
	return (1);
}

void	put_error(int error)
{
	print_error(error);
	exit(1);
}

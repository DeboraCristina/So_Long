/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:14:42 by desilva           #+#    #+#             */
/*   Updated: 2022/08/11 16:27:19 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	print_error(int error)
{
	if (error == MALLOC)
		ft_printf("\e[1;91mMalloc error.\n");
	if (error == INIT)
		ft_printf("\e[1;91mStartup error.\n");
	return (1);
}

void	put_error(int error)
{
	ft_printf("\e[1;91mError\n");
	print_error(error);
	exit(1);
}

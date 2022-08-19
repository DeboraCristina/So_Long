/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:31:03 by desilva           #+#    #+#             */
/*   Updated: 2022/06/15 02:34:06 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_str(char *s)
{
	int		len;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		len = 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		len = ft_strlen(s);
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:30:48 by desilva           #+#    #+#             */
/*   Updated: 2022/06/15 02:18:57 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_int(int i)
{
	char	*s;
	int		len;

	s = ft_itoa(i);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	if (s)
		free(s);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:53:07 by desilva           #+#    #+#             */
/*   Updated: 2022/05/15 20:50:08 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			count;
	unsigned char	l;

	str = (unsigned char *) s;
	count = 0;
	l = c;
	while (count++ < n)
		if (l == *str++)
			return ((void *)--str);
	return (0);
}

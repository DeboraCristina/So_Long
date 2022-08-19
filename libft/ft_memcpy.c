/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:13:06 by desilva           #+#    #+#             */
/*   Updated: 2022/04/19 08:13:07 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;
	char	*s;
	char	*d;

	count = 0;
	s = (char *) src;
	d = (char *) dest;
	while (count < n)
	{
		d[count] = s[count];
		count++;
	}
	return (dest);
}

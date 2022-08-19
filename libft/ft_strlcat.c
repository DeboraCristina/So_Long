/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:04:00 by desilva           #+#    #+#             */
/*   Updated: 2022/04/17 01:04:10 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	di;

	i = 0;
	di = 0;
	while (dst[di] && di < size)
		di++;
	while (src[i] && (di + i + 1) < size)
	{
		dst[di + i] = src[i];
		i++;
	}
	if (di != size)
		dst[di + i] = 0;
	return (di + ft_strlen((char *)src));
}

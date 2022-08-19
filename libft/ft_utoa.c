/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:00:59 by desilva           #+#    #+#             */
/*   Updated: 2022/06/15 00:25:09 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_digits(size_t n)
{
	size_t	c;

	c = 0;
	while (n > 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_utoa(unsigned int u)
{
	unsigned int	len;
	char			*num;

	len = (unsigned int) ft_count_digits(u);
	num = (char *) calloc(len + 1, sizeof(char));
	if (!num)
		return (NULL);
	while (len > 0)
	{
		num[len - 1] = (u % 10) + '0';
		u = u / 10;
		len--;
	}
	return (num);
}

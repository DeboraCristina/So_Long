/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:30:41 by desilva           #+#    #+#             */
/*   Updated: 2022/06/15 00:25:14 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_int(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static void	ft_takenbr(char	*dest, long long int n, int index)
{
	if (n / 10 != 0)
		ft_takenbr(dest, n / 10, index - 1);
	dest[index] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	long long int	lln;
	int				len;
	char			*num;

	lln = n;
	len = ft_count_int(lln);
	if (lln < 0)
	{
		lln *= -1;
		len++;
	}
	num = (char *) malloc(len + 1);
	if (!num)
		return (0);
	ft_bzero(num, len);
	ft_takenbr(num, lln, len - 1);
	if (!num[0])
		num[0] = '-';
	num[len] = 0;
	return (num);
}

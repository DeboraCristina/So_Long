/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 03:39:09 by desilva           #+#    #+#             */
/*   Updated: 2022/04/18 03:39:11 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_noprint(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	count;
	int	sinal;

	num = 0;
	count = 0;
	sinal = 1;
	while (str[count] == ' ' || ft_noprint(str[count]))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sinal = -1;
		count++;
	}
	while (ft_isdigit(str[count]))
	{
		num *= 10;
		num += str[count] - 48;
		count++;
	}
	return (num * sinal);
}

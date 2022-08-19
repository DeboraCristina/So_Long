/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u2hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:29:35 by desilva           #+#    #+#             */
/*   Updated: 2022/06/15 20:26:19 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbr2hex(unsigned long int i, int type, char *dest)
{
	char	n;

	if (i >= 10 && i <= 15)
	{
		if (ft_isupper(type))
			n = (i + 55);
		else
			n = (i + 87);
	}
	else
		n = (i + 48);
	dest[0] = n;
	dest[1] = '\0';
}

char	*ft_u2hex(unsigned int n, int type)
{
	char	*hex;
	char	*temp;
	char	res[2];

	hex = NULL;
	while (n > 0)
	{
		ft_nbr2hex((n % 16), type, res);
		temp = hex;
		hex = ft_strjoin(hex, res);
		free (temp);
		if (!hex)
			return (NULL);
		n = n / 16;
	}
	ft_rev_tab(hex, ft_strlen(hex));
	return (hex);
}

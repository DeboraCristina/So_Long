/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 03:37:49 by desilva           #+#    #+#             */
/*   Updated: 2022/05/15 20:50:31 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	l;
	char			*str;
	size_t			tam;

	l = c;
	str = (char *) s;
	tam = ft_strlen(s);
	while (tam)
	{
		if (str[tam] == l)
			return ((char *) s + tam);
		tam--;
	}
	if (str[0] == l)
		return ((char *) s + tam);
	return (0);
}

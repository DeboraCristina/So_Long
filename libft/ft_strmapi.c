/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 06:55:17 by desilva           #+#    #+#             */
/*   Updated: 2022/05/01 06:55:19 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		c;
	int		len;
	char	*map;

	c = 0;
	len = ft_strlen((char *) s);
	map = (char *) malloc(len + 1);
	if (!map)
		return (0);
	while (c < len)
	{
		map[c] = f(c, s[c]);
		c++;
	}
	map[c] = 0;
	return (map);
}

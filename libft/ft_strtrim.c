/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:21:30 by desilva           #+#    #+#             */
/*   Updated: 2022/05/10 15:18:14 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		len;
	int		start;
	int		c;

	c = 0;
	start = 0;
	len = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[len]))
		len--;
	len += 1;
	if (len - start <= 0)
		return (ft_strdup(""));
	else
		trim = (char *) malloc(len - start + 1);
	if (!trim)
		return (0);
	while (start < len)
		trim[c++] = s1[start++];
	trim[c] = 0;
	return (trim);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:25:37 by desilva           #+#    #+#             */
/*   Updated: 2022/06/08 03:50:48 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	int		lens1;
	int		lens2;
	int		count;

	lens1 = ft_strlen((char *) s1);
	lens2 = ft_strlen((char *) s2);
	sj = (char *) malloc(lens1 + lens2 + 1);
	count = 0;
	if (!sj)
		return (0);
	while (s1 && *s1)
		sj[count++] = *s1++;
	while (s2 && *s2)
		sj[count++] = *s2++;
	sj[count] = 0;
	return (sj);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:49:17 by desilva           #+#    #+#             */
/*   Updated: 2022/04/30 02:25:47 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t s)
{
	size_t	ib;
	size_t	il;

	if (!*l)
		return ((char *) b);
	ib = 0;
	while (b[ib] && ib < s)
	{
		il = 0;
		while (b[ib + il] == l[il] && l[il] && (ib + il) < s)
			il++;
		if (!l[il])
			return ((char *) b + ib);
		ib++;
	}	
	return (0);
}

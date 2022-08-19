/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:35:39 by desilva           #+#    #+#             */
/*   Updated: 2022/05/05 23:35:41 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cword(const char *str, char del)
{
	int	c;
	int	i;
	int	status;

	c = 0;
	i = 0;
	status = 0;
	while (str[i])
	{
		if (status == 0 && str[i] != del)
		{
			c++;
			status = 1;
		}
		else if (str[i] == del)
			status = 0;
		i++;
	}
	return (c);
}

static void	ft_strnlen(const char *str, int start, char del, int *pos)
{
	int	end;

	end = 0;
	while (str[start] && str[start] == del)
		start++;
	end = start;
	while (str[end])
	{
		if (str[end + 1] == 0 || str[end + 1] == del)
			break ;
		end++;
	}
	pos[0] = start;
	pos[1] = end;
}

char	**ft_split(char const *s, char c)
{
	int		ndel;
	int		pos[2];
	int		i;
	char	**result;

	ndel = ft_cword(s, c);
	pos[0] = 0;
	pos[1] = -1;
	i = 0;
	result = (char **) malloc((ndel + 1) * sizeof(char *));
	if (!result)
		return (0);
	result[ndel] = 0;
	while (i < ndel)
	{
		ft_strnlen(s, pos[1] + 1, c, pos);
		result[i] = ft_substr(s, pos[0], pos[1] - pos[0] + 1);
		i++;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:34:25 by desilva           #+#    #+#             */
/*   Updated: 2022/08/08 09:35:29 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_image
{
	int	id;
	int	x;
	int	y;
}	t_image;

typedef struct s_map
{
	char	*mapping;
	int		width;
	int		height;
}	t_map;

typedef struct s_window
{
	void	*window;
	int		width;
	int		height;
}	t_window;

typedef struct s_mlx
{
	void		*init;
	t_window	win;
	t_list		*objs;
	t_list		*xpm_images;
	int			movements;
	int			status;
}	t_mlx;

#endif

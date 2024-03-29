/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:34:25 by desilva           #+#    #+#             */
/*   Updated: 2022/08/18 15:55:29 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_image
{
	int	id;
	int	x;
	int	y;
	int	dir;
}	t_image;

typedef struct s_map
{
	char	*mapping;
	int		width;
	int		height;
	int		player;
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
	int			time;
	int			total_collectibles;
	int			collectibles;
	int			enemies;
}	t_mlx;

#endif

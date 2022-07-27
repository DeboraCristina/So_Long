/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:36:31 by desilva           #+#    #+#             */
/*   Updated: 2022/07/27 21:53:56 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# define K_ESCAPE 65307
# define SIZE 32

typedef struct s_image
{
	void	*img;
	int		x;
	int		y;
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
	int			status;
}	t_mlx;

// objects
void	gen_objects(t_mlx *mlx, t_list *objs, t_map *p_map);
char	*get_name(char c);

// maps
int		check_map(char *name);
t_map	map_generator(char *name);

// events
int		close_window(t_mlx *solong);
int		key_release(int key, t_mlx *solong);

// window manage
void	init_display(t_mlx *solong);
void	events_hook(t_mlx *solong);

#endif

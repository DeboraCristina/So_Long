/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <deboracristinaproficional1@gma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:34:32 by desilva           #+#    #+#             */
/*   Updated: 2022/08/11 16:00:47 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

# include "libft.h"
# include "key_maps.h"
# include "images.h"
# include "types.h"

# define SIZE 32

// errors
# define MALLOC 0
# define INIT 1

int	print_error(int error);
void	put_error(int error);

// objects
char	*get_name(char c);
t_list	*gen_objects(t_map *p_map);
t_list	*gen_images(void *p_mlx);
void	ft_destroy_images(void *p_mlx, t_list *lst);
void	ft_destroy_objs(t_list	*objs);

// maps
int		check_map(char *name);
t_map	map_generator(char *name);

// events
int		close_window(t_mlx *solong);
int		key_release(int key, t_mlx *solong);
int		render(t_mlx *solong);

// window manage
int	init_display(t_mlx *solong, t_map *p_map);
void	events_hook(t_mlx *solong);

// movements
void	execute_movement(t_mlx *solong, t_image *player, t_image *tile);
void	move(t_mlx *solong, t_list *objs, int mx, int my);
void	move_player(int key, t_mlx *solong);

#endif

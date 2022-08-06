#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

# include "libft.h"
# include "key_maps.h"
# include "images.h"
# include "types.h"

# define SIZE 32

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
void	init_display(t_mlx *solong, t_map *p_map);
void	events_hook(t_mlx *solong);

// movements
void	show_movements(int move);
void	execute_movement(t_mlx *solong, t_image *player, t_image *tile);
void	move(t_mlx *solong, t_list *objs, int mx, int my);
void	move_player(int key, t_mlx *solong);

#endif

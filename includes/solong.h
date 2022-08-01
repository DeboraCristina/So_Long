#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include "images.h"
# define XMP_TO_IMG mlx_xpm_file_to_image
# define K_ESCAPE 65307
# define SIZE 32

typedef struct s_image
{
	char	*name;
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
char	*get_name(char c);
t_list	*gen_objects(t_map *p_map);
t_list	*gen_images(void *p_mlx);
void	ft_destroy_images(void *p_mlx, t_list *lst);
void	ft_delimage(void *ptr_img);

// maps
int		check_map(char *name);
t_map	map_generator(char *name);

// events
int		close_window(t_mlx *solong);
int		key_release(int key, t_mlx *solong);

// window manage
void	init_display(t_mlx *solong, t_map *p_map);
void	events_hook(t_mlx *solong);

#endif

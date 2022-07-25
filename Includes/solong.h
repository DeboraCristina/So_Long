#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h> // write & read
# include <fcntl.h> // open & close
# include <stdlib.h> // malloc & free & exit
# include <mlx.h> //mlx
# include "libft.h"
# include "objects.h"

# define K_ESCAPE 65307

typedef struct	s_map
{
	char	*mapping;
	int		width;
	int		height;
}	t_map;

typedef struct	s_window
{
	void	*window;
	int		width;
	int		height;
}	t_window;

typedef struct	s_image
{
	void	*img;
	int		size;
	int		x;
	int		y;
}	t_image;

typedef struct	s_mlx
{
	void		*init;
	t_window	win;
	int			status;
}	t_mlx;

typedef struct	s_objlk
{
	t_image			*presets;
	struct s_objlk	*next;
}	t_objlk;

void	gen_objects(t_mlx *mlx, t_objlk *objs, t_map *p_map);
void	ft_objclear(t_objlk *obj);
void	ft_objadd_back(t_objlk **lst, t_objlk *new);
void	ft_objiter(t_objlk *obj, void (*function)(t_image *));
t_objlk	*ft_objlast(t_objlk *lst);
t_objlk	*ft_newobj(t_image *content);
char	*get_name(char c);
// maps
int	check_map(char *name);
t_map	map_generator(char *name);

// events
int		close_window(t_mlx *solong);
int		key_release(int key, t_mlx *solong);

// window manage
void	init_display(t_mlx *solong);
void	events_hook(t_mlx *solong);

#endif

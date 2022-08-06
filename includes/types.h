#ifndef TYPES_S
# define TYPES_S

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

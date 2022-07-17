#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h> // write & read
# include <fcntl.h> // open & close
# include <stdlib.h> // malloc & free & exit
# include <mlx.h> //mlx
# include "libft.h"

# define K_ESCAPE 65307

typedef struct	s_window
{
	void	*window;
	int		width;
	int		height;
}	t_window;

typedef struct	s_image
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_image;

typedef struct	s_mlx
{
	void		*instance;
	t_window	win;
	int			status;
}	t_mlx;

#endif

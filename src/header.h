#ifndef HEADER_H
# define HEADER_H

# include <unistd.h> // write & read
# include <fcntl.h> // open & close
# include <stdlib.h> // malloc & free & exit
# include <mlx.h> //mlx

typedef struct	s_data
{
	void	*mlx;
	void	*win;
}	t_data;

#endif

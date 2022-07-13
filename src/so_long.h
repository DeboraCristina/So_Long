#ifndef HEADER_H
# define HEADER_H

# include <unistd.h> // write & read
# include <fcntl.h> // open & close
# include <stdlib.h> // malloc & free & exit
# include <mlx.h> //mlx
# include "libft.h"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
}	t_data;

// events manage
int		ft_readInputKeys(int key, t_data *mlx);

// window manage
void	ft_close_window(int key, t_data *mlx);

#endif

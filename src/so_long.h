#ifndef HEADER_H
# define HEADER_H

# include <unistd.h> // write & read
# include <fcntl.h> // open & close
# include <stdlib.h> // malloc & free & exit
# include <mlx.h> //mlx
# include "libft.h"
# include "utils.h"

typedef struct	s_window
{
	void	*win;
	int		width;
	int		heigh;
}	t_window;

typedef struct	s_data
{
	void		*mlx;
	t_window	win;
}	t_data;

// events manage
int	ft_readInputKeys(int key, t_data *mlx);

// window manage
int	ft_close_window(t_data *mlx);

int	update_window(t_data *mlx);

// grafic utils
int	ft_draw_background(t_data *mlx, int color);

int	ft_draw_rect(t_data *mlx, t_rect rect);

#endif

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

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct	s_data
{
	void		*mlx;
	t_window	win;
	t_img		img; // ??????
}	t_data;

// events manage
int	ft_readInputKeys(int key, t_data *mlx);

// window manage
int	ft_close_window(t_data *mlx);

int	update_window(t_data *mlx);

// grafic utils
void	img_pixel_put(t_img *img, int x, int y, int color);

void	ft_draw_rect(t_img *img, t_rect rect);

void	ft_draw_background(t_data *mlx, int color);

#endif

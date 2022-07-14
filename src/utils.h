#ifdef UTILS_H
# define UTILS_H

# define K_ESCAPE 65307
//# define 

// colors
# define RED	0x00ff0000
# define GREEN	0x0000ff00
# define BLUE	0x000000ff
# define WHITE	0x00ffffff

// forms
typedef struct	s_rect
{
	int	x;
	int	y;
	int	width;
	int	heigh;
	int	color;
}	t_rect;

#endif

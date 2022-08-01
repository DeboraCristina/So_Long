#include "solong.h"

void	ft_delimage(void *ptr_img)
{
	t_image	*img;

	img = (t_image *) ptr_img;
	free(img);
}

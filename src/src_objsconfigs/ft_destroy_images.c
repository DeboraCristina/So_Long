#include "solong.h"

void	ft_destroy_images(void *p_mlx, t_list *lst)
{
	if (lst)
	{
		ft_destroy_images(p_mlx, lst->next);
		mlx_destroy_image(p_mlx, lst->content);
		free(lst);
	}
}
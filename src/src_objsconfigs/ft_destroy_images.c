#include "solong.h"

void	ft_destroy_images(void *p_mlx, t_list *lst)
{
	t_list	*temp;

	if (!p_mlx || !lst)
		return ;
	while (lst)
	{
		temp = lst;
		lst = (lst)->next;
		mlx_destroy_image(p_mlx, temp->content);
		free(temp);
	}
	lst = NULL;
}

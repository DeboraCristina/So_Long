#include "solong.h"

void	ft_objclear(t_mlx *solong, t_objlk *obj)
{
	t_objlk	*temp;

	if (!obj)
		return ;
	while (obj)
	{
		temp = obj;
		obj = obj->next;
		mlx_destroy_image(solong->init, obj->presets->img);
		free(temp->presets);
		free(temp);
	}
	obj = NULL;
}

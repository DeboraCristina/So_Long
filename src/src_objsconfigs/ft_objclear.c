#include "solong.h"

void	ft_objclear(t_objlk *obj)
{
	t_objlk	*temp;

	if (!obj)
		return ;
	while (obj)
	{
		temp = obj;
		obj = obj->next;
		free(temp->presets);
		free(temp);
	}
	obj = NULL;
}

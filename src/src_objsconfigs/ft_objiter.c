#include "solong.h"

// void	ft_objiter(t_objlk *obj, void (*function)(t_image *))
// {
// 	if (!obj || !function)
// 		return ;
// 	while (obj)
// 	{
// 		function(obj->presets);
// 		obj = obj->next;
// 	}
// }

void	ft_objiter(t_objlk *obj, void (*function)(t_image *))
{
	if (!obj || !function)
	{
		ft_objiter(obj->next, function);
		function(obj->presets);
	}
}

#include "solong.h"

t_objlk	*ft_newobj(void *presets)
{
	t_objlk	*newnode;

	newnode = (t_objlk *) malloc(sizeof(t_objlk));
	if (!newnode)
		return (NULL);
	newnode->presets = presets;
	newnode->next = NULL;
	return (newnode);
}

#include "solong.h"

t_objlk	*ft_objlast(t_objlk *lst)
{
	if (!lst)
		return ((t_objlk *) NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

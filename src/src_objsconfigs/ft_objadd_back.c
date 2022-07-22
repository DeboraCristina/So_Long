#include "solong.h"

void	ft_objadd_back(t_objlk **lst, t_objlk *new)
{
	t_objlk	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_objlast(*lst);
		last->next = new;
	}
}

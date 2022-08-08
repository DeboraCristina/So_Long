#include "solong.h"

int	print_error(int error)
{
	if (error == MALLOC)
		ft_printf("\e[1;91mError:Malloc error.\n");
	if (error == INIT)
		ft_printf("\e[1;91mError:Startup error.\n");
	return (1);
}
void	put_error(int error)
{
	print_error(error);
	exit(1);
}

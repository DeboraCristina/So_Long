#include "solong.h"

char	*get_name(char c)
{
	char	*name;

	if (c == '1')
		name = "images/wall_32.xpm";
	else if (c == 'P')
		name = "images/Enemy_Animation/Enemy_run_32_1.xpm";
	else if (c == 'C')
		name = "images/coletable01_32.xpm";
	else if (c == 'E')
		name = "exit";
	else if (c == 'D')
		name = "devil";
	else
		name = "null";
	return (name);
}

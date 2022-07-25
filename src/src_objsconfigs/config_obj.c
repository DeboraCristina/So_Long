#include "solong.h"

char	*get_name(char c)
{
	char	*name;

	if (c == '1')
		name = "wall";
	else if (c == 'P')
		name = "player";
	else if (c == 'C')
		name = "coletable";
	else if (c == 'E')
		name = "exit";
	else if (c == 'D')
		name = "devil";
	else
		name = "null";
	return (name);
}

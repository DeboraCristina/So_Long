#include "solong.h"

int	check_map(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 5 || ft_strcmp((name + (len - 4)), ".ber"))
		return(0);
	return(1);
}

int	valid_map(char *name)
{
	int		filedescriptor;
	char	*line;
	char	*validation;

	ft_bezero(validation);
	filedescriptor = open(name, O_RDONLY);
	while (1)
	{
		line = get_next_line(filedescriptor);
		if (!line)
			break ;
	}
	return(1);
}

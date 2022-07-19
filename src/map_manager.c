#include "solong.h"
#include "utils_map.h"

int	check_map_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 5 || ft_strcmp((name + (len - 4)), ".ber"))
		return(0);
	return(1);
}

int	valid_map_elements(char *name)
{
	int		filedescriptor;
	char	*line;
	int		count;
	int		last_line;

	count = 0;
	filedescriptor = open(name, O_RDONLY);
	last_line = line_counter(name);
	if (filedescriptor < 0)
		return (0);
	line = gnl(filedescriptor);
	if (!line)
		return (0);
	while (line)
	{
		if (!valid_elements(count, last_line, line))
			return (0);
		free(line);
		line = gnl(filedescriptor);
		count++;
	}
	close(filedescriptor);
	return(1);
}

int	minimum_elements(char *name)
{
	int		*minimuns[3];

	return (1);
}

int	check_map(char *name)
{
	if (!check_map_name(name))
	{
		// erro de nome
		return (0);
	}
	if (!valid_map_elements(name))
	{
		// erro de formatação de texto
		return (0);
	}
	if (!minimum_elements(name))
	{
		// não tem os elementos minimos
		return (0);
	}
	return(1);
}

#include "solong.h"
#include "utils_map.h"

int	valid_map_elements(char *name)
{
	int		filedescriptor;
	char	*line;
	int		count;
	int		last_line;

	count = 0;
	filedescriptor = open(name, O_RDONLY);
	last_line = row_counter(name);
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
	int		minimum[3];

	minimum[0] = 0;
	minimum[1] = 0;
	minimum[2] = 0;
	gen_minimuns(minimum, name);
	if (!minimum[0] || !minimum[1] || !minimum[2])
		return (0);
	return (1);
}

int	check_map_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 5 || ft_strcmp((name + (len - 4)), ".ber"))
		return(0);
	return(1);
}

int	check_map(char *name)
{
	char	*error;

	error = NULL;
	if (!check_map_name(name))
	{
		// erro de nome
		error = "name";
	}
	else if (!valid_map_elements(name))
	{
		// erro de formatação de texto
		error = "text";
	}
	else if (!minimum_elements(name))
	{
		// não tem os elementos minimos
		error = "minimum elements";
	}
	if (error)
	{
		ft_printf("Error! -- %s --\n", error);
		return (0);
	}
	return(1);
}

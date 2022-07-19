#include "solong.h"
#include "utils_map.h"

int	check_char(char *set, char *str)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (str[i])
	{
		j = 0;
		status = 0;
		while (set[j])
		{
			if (str[i] == set[j])
			{
				status = 1;
				break ;
			}
			j++;
		}
		if (!status)
			return (0);
		i++;
	}
	return (1);
}

int	valid_elements(int index, int last, char *row)
{
	static int	default_len;
	int			status;
	int			len;

	len = ft_strlen(row);
	if (row[len - 1] == '\n')
		len--;
	if (index == 0)
		default_len = len;
	if (default_len != len)
		return (0);
	if (index == 0 || index == (last - 1))
		status = check_char("1\n", row);
	else
	{
		if (row[0] != '1' || row[len - 1] != '1')
			return (0);
		status = check_char("01PCED\n", row);
	}
	return (status);
}

int	line_counter(char *name)
{
	int		c;
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	c = 0;
	if (fd > 0)
	{
		line = gnl(fd);
		while (line)
		{
			free(line);
			c ++;
			line = gnl(fd);
		}
	}
	close(fd);
	return (c);
}

void	gen_minimuns(int *minimum, char *name)
{
	int		fd;
	int		c;
	char	*line;

	fd = open(name, O_RDONLY);
	line = gnl(fd);
	while (line)
	{
		c = 0;
		while (line[c])
		{
			if (line[c] == 'P')
				minimum[0] += 1;
			else if (line[c] == 'E')
				minimum[1] += 1;
			else if (line[c] == 'C')
				minimum[2] += 1;
		}
		free(line);
		line = gnl(fd);
	}
	close(fd);
}


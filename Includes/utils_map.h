#ifndef UTILS_MAP_H
# define UTILS_MAP_H

int		check_char(char *set, char *str);
int		check_linelen(int *default_len , int index, char *row);
int		valid_elements(int index, int last, char *row);
int	row_counter(char *name);
void	gen_minimuns(int *minimum, char *name);

#endif

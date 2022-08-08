/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:30:30 by desilva           #+#    #+#             */
/*   Updated: 2022/08/08 09:34:33 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MANAGER_H
# define MAP_MANAGER_H

// map utils
int		row_counter(char *name);

// map checker
int		valid_map_elements(char *name);
int		minimum_elements(char *name);
int		check_map_name(char *name);
int		check_char(char *set, char *str);
int		check_linelen(int *default_len, int index, char *row);
int		valid_elements(int index, int last, char *row);
void	gen_minimuns(int *minimum, char *name);

// map configing
void	gen_maplst(char *name, t_map *p_map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:28:19 by desilva           #+#    #+#             */
/*   Updated: 2022/06/15 16:28:21 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_replace_placeholder(int ph, va_list items)
{
	int	len;

	len = 0;
	if (ph == 'd' || ph == 'i')
		len = ft_print_int(va_arg(items, int));
	else if (ph == 'c')
		len = ft_print_char(va_arg(items, int));
	else if (ph == '%')
		len = ft_print_char('%');
	else if (ph == 's')
		len = ft_print_str(va_arg(items, char *));
	else if (ph == 'x' || ph == 'X')
		len = ft_print_hex(ph, va_arg(items, int));
	else if (ph == 'u')
		len = ft_print_unint(va_arg(items, unsigned int));
	else if (ph == 'p')
		len = ft_print_ptr(va_arg(items, unsigned long int));
	return (len);
}

static int	ft_identify_placeholder(const char *str, va_list args)
{
	char	*temp;
	int		s;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		s = i;
		while (str[i] && str[i] != '%')
			i++;
		temp = ft_substr(str, s, i - s);
		ft_putstr_fd(temp, 1);
		len += ft_strlen(temp);
		if (str[i] == '%' && ft_isvalidparam(str[i + 1]))
		{
			len += ft_replace_placeholder(str[i + 1], args);
			i++;
		}
		free(temp);
		if (str[i])
			i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	parameters;
	int		len;

	va_start(parameters, str);
	len = ft_identify_placeholder(str, parameters);
	va_end(parameters);
	return (len);
}

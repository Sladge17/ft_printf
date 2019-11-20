/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_lengths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:12:48 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/20 18:23:18 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		def_width(const char **str)
{
	int		width;

	width = 0;
	while ('0' <= **str && **str <= '9')
	{
		width = width * 10 + (**str - '0');
		*str += 1;
	}
	return (width);
}

int		len_numb(int value_d, char len_sign)
{
	int		len;

	len = 1;
	value_d = value_d < 0 ? (-1) * value_d : value_d;
	while (value_d > 9)
	{
		value_d /= 10;
		len += 1;
	}
	return (len + len_sign);
}

int		len_unumb(unsigned int value_d)
{
	int		len;

	len = 1;
	while (value_d > 9)
	{
		value_d /= 10;
		len += 1;
	}
	return (len);
}

char	len_sign(int value_d, char flags)
{
	// if (flags & 32)
	// 	return (0); 
	if (value_d < 0)
		return (1);
	if (flags & 2 || flags & 4)
		return (1);
	return (0);
}

int		len_str(const char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len += 1;
	return (len);
}

int		len_space(int width, const char **str, void *value, char flags)
{
	int		len_space;
	int		len_symbols;

	len_symbols = 1;
	if (**str == 'd' || **str == 'i' || flags & 32)
		len_symbols = len_numb(*(int *)value, len_sign(*(int *)value, flags));
	if (**str == 'u')
		len_symbols = len_unumb(*(int *)value);
	if (**str == 's')
		len_symbols = len_str((char *)value);
	len_space = width - len_symbols;
	return (len_space);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_lengths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:12:48 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/21 17:24:33 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_numb(int value, char len_sign)
{
	int		len;

	len = 1;
	value = value < 0 ? (-1) * value : value;
	while (value > 9)
	{
		value /= 10;
		len += 1;
	}
	return (len + len_sign);
}

int		len_unumb(unsigned int value)
{
	int		len;

	len = 1;
	while (value > 9)
	{
		value /= 10;
		len += 1;
	}
	return (len);
}

char	len_sign(int value, char flags)
{
	// if (flags & 32)
	// 	return (0); 
	if (value < 0)
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
	if (**str == 'o' && flags & 8)
		len_symbols += 1;
	len_space = width - len_symbols;
	return (len_space);
}
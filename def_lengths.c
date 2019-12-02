/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_lengths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:12:48 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/02 17:19:15 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		len_numb(int value, char len_sign)
int		len_numb(int value)
{
	int		len;

	len = 1;
	value = value < 0 ? (-1) * value : value;
	while (value > 9)
	{
		value /= 10;
		len += 1;
	}
	// return (len + len_sign);
	return (len);
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

char	len_sign(void *value, short *flags)
{
	// if (flags & 32)
	// 	return (0);
	if (*flags & 128)
		return (0);
	if (*(int *)value < 0)
		return (1);
	if (*flags & 2 || *flags & 4)
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

// int		len_space(const char **str, void *value, short flags)
int		len_symbols(const char **str, void *value, short *flags)
{
	// extern int	g_width; //DELL
	// int			len_space; // DELL
	int			len_symbols;

	len_symbols = 1;
	if (**str == 'd' || **str == 'i')
		// len_symbols = len_numb(*(int *)value, len_sign(*(int *)value, flags));
		len_symbols = len_numb(*(int *)value);
	if (**str == 'u')
		len_symbols = len_unumb(*(int *)value);
	if (**str == 's' || **str == 'o' || **str == 'x' || **str == 'X')
		len_symbols = len_str((char *)value);
	if (**str == 'o' && *flags & 8)
		len_symbols += 1;
	if (*flags & 8 && (**str == 'x' || **str == 'X'))
		len_symbols += 2;
	// len_space = g_width - len_symbols;
	return (len_symbols);
}

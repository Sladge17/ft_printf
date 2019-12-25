/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:43:36 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/25 17:58:26 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	exe_float(long double *value_f, int *flags, const char **str, int *amt)
{
	long int	unit;
	char		*remainder;
	extern int	g_accuracy;

	if (!(*flags & 1048576))
		return (0);
	if (!(*flags & 64))
		g_accuracy = 6;
	if (*flags & 32 && !(*flags & 1) && !(*flags & 16))
		put_space_f(&(*value_f), &(*flags), &(*amt));
	put_sign_f(&(*value_f), &(*flags), &(*amt));
	if ((*flags & 48) == 48 && !(*flags & 1))
		put_space_f(&(*value_f), &(*flags), &(*amt));
	unit = *value_f < 0 ? -(long int)(*value_f) : (long int)(*value_f);
	remainder = (char *)malloc(sizeof(char) * 21);
	if (!remainder)
		exit(0);
	def_remainder(&remainder, *value_f, unit);
	fix_float(&unit, &remainder);
	put_float(&unit, &remainder, &(*flags), &(*amt));
	free(remainder);
	if ((*flags & 33) == 33)
		put_space_f(&(*value_f), &(*flags), &(*amt));
	*str += 1;
	return (1);
}

void	put_space_f(long double *value_f, int *flags, int *amt)
{
	extern int	g_width;
	int			len_symbols;
	char		space;
	int			len_space;
	int			i;

	def_lensymbols_f(&len_symbols, &(*value_f));
	space = *flags & 16 && !(*flags & 1) ? '0' : ' ';
	len_space = g_width - len_symbols - len_sign_f(&(*value_f), &(*flags));
	if ((*flags & 8 && !g_accuracy))
		len_space -= 1;
	i = 0;
	while (i < len_space)
	{
		put_char(space, NULL, &(*amt));
		i += 1;
	}
}

void	def_lensymbols_f(int *len_symbols, long double *value_f)
{
	extern int	g_accuracy;
	int			unit;

	unit = *value_f < 0 ? -(int)(*value_f) : (int)(*value_f);
	*len_symbols = len_unumb(unit) + g_accuracy;
	if (g_accuracy)
		*len_symbols += 1;

	// *len_symbols = g_lenarg;
	// if ((*flags & 64 && *flags & 12288 && *len_symbols < g_accuracy)
	// 	|| (*flags & 64 && !g_accuracy && !(*value) && !(*flags & 32768))
	// 	|| ((*flags & 16480) == 16480 && *len_symbols > g_accuracy)
	// 	|| (*flags & 64 && *flags & 229376 && *len_symbols < g_accuracy))
	// 	*len_symbols = g_accuracy;
	// if (((*flags & 32776) == 32776 && *flags & 64
	// 	&& *len_symbols > g_accuracy && *value)
	// 	|| ((*flags & 32776) == 32776 && !(*flags & 64) && *value))
	// 	*len_symbols += 1;
	// if ((*flags & 8 && *flags & 196608 && *value) || *flags & 524288)
	// 	*len_symbols += 2;
}

void	put_sign_f(long double *value_f, int *flags, int *amt)
{
	if (*value_f < 0)
	{
		put_char('-', NULL, &(*amt));
		return ;
	}
	if (*flags & 2)
	{
		put_char('+', NULL, &(*amt));
		return ;
	}
	if (*flags & 4)
	{
		put_char(' ', NULL, &(*amt));
		return ;
	}
}

void	def_remainder(char **remainder, long double value_f, long int unit)
{
	extern int	g_accuracy;
	int			i;

	value_f = value_f < 0 ? -value_f : value_f;
	i = 0;
	while (i < 21)
	{
		value_f = 10 * (value_f - unit);
		unit = (char)value_f;
		(*remainder)[i] = unit;
		i += 1;
	}
	i = 19;
	if ((*remainder)[i] > 4 && i != g_accuracy)
		(*remainder)[i - 1] += 1;
	i -= 1;
	while (i > g_accuracy)
	{
		if ((*remainder)[i] == 10)
			(*remainder)[i - 1] += 1;
		i -= 1;
	}
}

void	fix_float(long int *unit, char **remainder)
{
	extern int	g_accuracy;
	int			i;

	i = g_accuracy;
	if (i == 0 && (*remainder)[i] > 4)
		*unit += 1;
	if ((*remainder)[i] > 4 && i)
	{
		(*remainder)[i - 1] += 1;
		i -= 1;
	}
	while ((*remainder)[i] > 9)
	{
		if (!i)
		{
			*unit += 1;
			(*remainder)[i] = 0;
			break ;
		}
		(*remainder)[i] = 0;
		(*remainder)[i - 1] += 1;
		i -= 1;
	}
}

void	put_float(long int *unit, char **remainder, int *flags, int *amt)
{
	extern int	g_accuracy;
	int			i;

	put_uabs((void *)unit, &(*flags), &(*amt));
	if (g_accuracy || *flags & 8)
		put_char('.', NULL, &(*amt));
	i = 0;
	while (i < g_accuracy)
	{
		put_char((*remainder)[i] + 48, NULL, &(*amt));
		i += 1;
	}
}
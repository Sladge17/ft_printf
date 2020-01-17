/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:43:36 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/17 13:26:28 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fixput_float(long int *unit, char **remainder, int *amt)
{
	fix_float(&(*unit), &(*remainder));
	put_float(&(*unit), &(*remainder), &(*amt));
}

char	exe_float(long double *value_f, const char **str, int *amt)
{
	long int	unit;
	char		*remainder;
	extern int	g_flags;
	extern int	g_accuracy;

	if (!(g_flags & 1048576))
		return (0);
	if (!(g_flags & 64))
		g_accuracy = 6;
	if (g_flags & 32 && !(g_flags & 1) && !(g_flags & 16))
		put_space_f(&(*value_f), &(*amt));
	put_sign_f(&(*value_f), &(*amt));
	if ((g_flags & 48) == 48 && !(g_flags & 1))
		put_space_f(&(*value_f), &(*amt));
	unit = *value_f < 0 ? -(long int)(*value_f) : (long int)(*value_f);
	remainder = (char *)malloc(sizeof(char) * 21);
	if (!remainder)
		exit(0);
	def_remainder(&remainder, *value_f, unit);
	fixput_float(&unit, &remainder, &(*amt));
	free(remainder);
	if ((g_flags & 33) == 33)
		put_space_f(&(*value_f), &(*amt));
	*str += 1;
	return (1);
}

void	put_space_f(long double *value_f, int *amt)
{
	extern int	g_flags;
	extern int	g_width;
	int			len_symbols;
	char		space;
	int			len_space;

	def_lensymbols_f(&len_symbols, &(*value_f));
	space = g_flags & 16 && !(g_flags & 1) ? '0' : ' ';
	len_space = g_width - len_symbols - len_sign_f(&(*value_f));
	if ((g_flags & 8 && !g_accuracy))
		len_space -= 1;
	putcycle(space, len_space, &(*amt));
}

void	def_lensymbols_f(int *len_symbols, long double *value_f)
{
	extern int	g_accuracy;
	int			unit;

	unit = *value_f < 0 ? -(int)(*value_f) : (int)(*value_f);
	*len_symbols = len_unumb(unit) + g_accuracy;
	if (g_accuracy)
		*len_symbols += 1;
}

void	put_sign_f(long double *value_f, int *amt)
{
	extern int	g_flags;

	if (*value_f < 0)
	{
		put_char('-', NULL, &(*amt));
		return ;
	}
	if (g_flags & 2)
	{
		put_char('+', NULL, &(*amt));
		return ;
	}
	if (g_flags & 4)
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

void	put_float(long int *unit, char **remainder, int *amt)
{
	extern int	g_flags;
	extern int	g_accuracy;
	int			i;

	put_uabs((void *)unit, &(*amt), &g_flags);
	if (g_accuracy || g_flags & 8)
		put_char('.', NULL, &(*amt));
	i = 0;
	while (i < g_accuracy)
	{
		put_char((*remainder)[i] + 48, NULL, &(*amt));
		i += 1;
	}
}

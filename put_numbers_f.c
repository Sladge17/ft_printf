/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:56:58 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/21 17:33:50 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_sign_f(long double *value_f, int *amt)
{
	extern int	g_flags;

	if (*value_f < 0)
	{
		put_char('-', NULL, amt);
		return ;
	}
	if (g_flags & 2)
	{
		put_char('+', NULL, amt);
		return ;
	}
	if (g_flags & 4)
	{
		put_char(' ', NULL, amt);
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

void	fixput_float(long int *unit, char **remainder, int *amt)
{
	fix_float(unit, remainder);
	put_float(unit, remainder, amt);
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

	put_uabs((void *)unit, amt, &g_flags);
	if (g_accuracy || g_flags & 8)
		put_char('.', NULL, amt);
	i = 0;
	while (i < g_accuracy)
	{
		put_char((*remainder)[i] + 48, NULL, amt);
		i += 1;
	}
}

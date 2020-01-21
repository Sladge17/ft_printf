/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_symbols_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:48:58 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/21 17:35:10 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_space(void **value, int *amt)
{
	extern int	g_flags;
	extern int	g_width;
	int			len_symbols;
	char		space;
	int			len_space;

	def_lensymbols(&len_symbols, value);
	space = g_flags & 16 && !(g_flags & 1) ? '0' : ' ';
	len_space = g_width - len_symbols - len_sign(value);
	put_charcycle(space, len_space, amt);
}

void	def_lensymbols(int *len_symbols, void **value)
{
	extern int	g_flags;
	extern int	g_accuracy;
	extern int	g_lenarg;

	*len_symbols = g_lenarg;
	if ((g_flags & 64 && g_flags & 12288 && *len_symbols < g_accuracy)
		|| (g_flags & 64 && !g_accuracy && !(*value) && !(g_flags & 32768))
		|| ((g_flags & 16480) == 16480 && *len_symbols > g_accuracy)
		|| (g_flags & 64 && g_flags & 229376 && *len_symbols < g_accuracy))
		*len_symbols = g_accuracy;
	if (((g_flags & 32776) == 32776 && g_flags & 64
		&& *len_symbols > g_accuracy && *value)
		|| ((g_flags & 32776) == 32776 && !(g_flags & 64) && *value))
		*len_symbols += 1;
	if ((g_flags & 8 && g_flags & 196608 && *value) || g_flags & 524288)
		*len_symbols += 2;
}

void	put_zero(void **value, int *amt)
{
	extern int	g_flags;
	extern int	g_accuracy;
	extern int	g_lenarg;
	int			len_zero;
	int			len_symbols;

	if (g_flags & 16384 || !(g_flags & 64) || (!g_accuracy && !(*value)))
		return ;
	len_symbols = g_lenarg;
	if ((g_flags & 32776) == 32776)
		len_symbols += 1;
	if (g_accuracy <= len_symbols)
		return ;
	len_zero = g_accuracy - len_symbols;
	put_charcycle('0', len_zero, amt);
}

void	put_space_f(long double *value_f, int *amt)
{
	extern int	g_flags;
	extern int	g_width;
	int			len_symbols;
	char		space;
	int			len_space;

	def_lensymbols_f(&len_symbols, value_f);
	space = g_flags & 16 && !(g_flags & 1) ? '0' : ' ';
	len_space = g_width - len_symbols - len_sign_f(value_f);
	if ((g_flags & 8 && !g_accuracy))
		len_space -= 1;
	put_charcycle(space, len_space, amt);
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

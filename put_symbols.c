/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:06:10 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/23 18:43:53 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char symbol, const char **str, int *amount)
{
	write(1, &symbol, 1);
	if (str)
		*str += 1;
	*amount += 1;
}

char	put_freesmb(const char **str, int *amount)
{
	while (**str != '%')
	{
		if (**str == '\0')
			return (0);
		put_char(**str, &(*str), &(*amount));
	}
	*str += 1;
	return (1);
}

char	check_lastfreesmb(const char **str, int *amount)
{
	int		i;

	if (**str != ' ' || *(*str + 1) == '\0')
		return (0);
	i = 1;
	while (*(*str + i) == ' ')
		i += 1;
	if (*(*str + i) == 'h' || *(*str + i) == 'l' || *(*str + i) == 'L')
		return (0);
	if (*(*str + i) == '-' || *(*str + i) == '+'|| *(*str + i) == '#' || *(*str + i) == '.'
		|| ('0' <= *(*str + i) && *(*str + i) <= '9') || *(*str + i) == 'c' 
		|| *(*str + i) == 'd' || *(*str + i) == 'i' 
		|| *(*str + i) == 'u' || *(*str + i) == 'o'
		|| *(*str + i) == 'x' || *(*str + i) == 'X')
		return (0);
	*str += i;
	put_char(**str, &(*str), &(*amount));
	return (1);
}

void	put_space(void **value, unsigned int *flags, int *amount)
{
	extern int	g_width;
	int			len_symbols;
	char		space;
	int			len_space;
	int			i;

	def_lensymbols(&len_symbols, &(*value), &(*flags));
	space = *flags & 16 && !(*flags & 1) ? '0' : ' ';
	len_space = g_width - len_symbols - len_sign(&(*value), &(*flags));
	i = 0;
	while (i < len_space)
	{
		put_char(space, NULL, &(*amount));
		i += 1;
	}
}

void	put_space_f(long double *value_f, unsigned int *flags, int *amount)
{
	extern int	g_width;
	int			len_symbols;
	char		space;
	int			len_space;
	int			i;

	def_lensymbols_f(&len_symbols, &(*value_f), &(*flags));
	space = *flags & 16 && !(*flags & 1) ? '0' : ' ';
	len_space = g_width - len_symbols - len_sign_f(&(*value_f), &(*flags));
	// if ((*flags & 8 && !g_accuracy) || (*flags & 2 && *value_f > 0))
	if ((*flags & 8 && !g_accuracy))
		len_space -= 1;
	i = 0;
	while (i < len_space)
	{
		put_char(space, NULL, &(*amount));
		i += 1;
	}
}

void	def_lensymbols_f(int *len_symbols, long double *value_f, unsigned int *flags)
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

void	def_lensymbols(int *len_symbols, void **value, unsigned int *flags)
{
	extern int	g_accuracy;
	extern int	g_lenarg;

	*len_symbols = g_lenarg;
	if ((*flags & 64 && *flags & 12288 && *len_symbols < g_accuracy)
		|| (*flags & 64 && !g_accuracy && !(*value) && !(*flags & 32768))
		|| ((*flags & 16480) == 16480 && *len_symbols > g_accuracy)
		|| (*flags & 64 && *flags & 229376 && *len_symbols < g_accuracy))
		*len_symbols = g_accuracy;
	if (((*flags & 32776) == 32776 && *flags & 64
		&& *len_symbols > g_accuracy && *value)
		|| ((*flags & 32776) == 32776 && !(*flags & 64) && *value))
		*len_symbols += 1;
	if ((*flags & 8 && *flags & 196608 && *value) || *flags & 524288)
		*len_symbols += 2;
}

void	put_zero(void **value, unsigned int *flags, int *amount)
{
	extern int	g_accuracy;
	extern int	g_lenarg;
	int			len_zero;
	int			i;
	int			len_symbols;

	if (*flags & 16384 || !(*flags & 64) || (!g_accuracy && !(*value)))
		return ;

	len_symbols = g_lenarg;
	if ((*flags & 32776) == 32776)
		len_symbols += 1;
	if (g_accuracy <= len_symbols)
		return ;
	len_zero = g_accuracy - len_symbols;
	i = 0;
	while (i < len_zero)
	{
		put_char('0', NULL, &(*amount));
		i += 1;
	}
}


void	put_str(char *value, unsigned int *flags, int *amount)
{
	extern int	g_accuracy;
	int			i;
	
	if (*flags & 12288 || (*flags & 229376 && !value)
		|| (*flags & 524288 && !value))
		return ;
	if (!value)
		value = "(null)";
	if (*flags & 64 && !(*flags & 753664) && *value != '\0')
	{
		i = 0;
		while (i < g_accuracy && *value != '\0')
		{
			put_char(*value, NULL, &(*amount));
			value += 1;
			i += 1;
		}
		return ;
	}
	while (*value != '\0')
	{
		put_char(*value, NULL, &(*amount));
		value += 1;
	}
}

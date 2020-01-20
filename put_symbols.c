/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:06:10 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/20 12:02:15 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char symbol, const char **str, int *amt)
{
	write(1, &symbol, 1);
	if (str)
		*str += 1;
	*amt += 1;
}

char	put_freesmb(const char **str, int *amt)
{
	while (**str != '%')
	{
		if (**str == '\0')
			return (0);
		put_char(**str, &(*str), &(*amt));
	}
	*str += 1;
	return (1);
}

char	put_lastfreesmb(const char **str, int *amt)
{
	int		i;

	if (**str != ' ' || *(*str + 1) == '\0')
		return (0);
	i = 1;
	while (*(*str + i) == ' ')
		i += 1;
	if (*(*str + i) == 'h' || *(*str + i) == 'l' || *(*str + i) == 'L')
		return (0);
	if (*(*str + i) == '-' || *(*str + i) == '+'
		|| *(*str + i) == '#' || *(*str + i) == '.'
		|| ('0' <= *(*str + i) && *(*str + i) <= '9') || *(*str + i) == 'c'
		|| *(*str + i) == 'd' || *(*str + i) == 'i'
		|| *(*str + i) == 'u' || *(*str + i) == 'o'
		|| *(*str + i) == 'x' || *(*str + i) == 'X')
		return (0);
	*str += i;
	put_char(**str, &(*str), &(*amt));
	return (1);
}

void	put_str(char *value, int *amt)
{
	extern int	g_flags;
	extern int	g_accuracy;
	int			i;

	if (g_flags & 12288 || (g_flags & 229376 && !value)
		|| (g_flags & 524288 && !value))
		return ;
	if (!value)
		value = "(null)";
	if (g_flags & 64 && !(g_flags & 753664) && *value != '\0')
	{
		i = 0;
		while (i < g_accuracy && *value != '\0')
		{
			put_char(*value, NULL, &(*amt));
			value += 1;
			i += 1;
		}
		return ;
	}
	while (*value != '\0')
	{
		put_char(*value, NULL, &(*amt));
		value += 1;
	}
}




void	putcycle(char symbol, int border, int *amt)
{
	int		i;

	i = 0;
	while (i < border)
	{
		put_char(symbol, NULL, &(*amt));
		i += 1;
	}
}

void	put_space(void **value, int *amt)
{
	extern int	g_flags;
	extern int	g_width;
	int			len_symbols;
	char		space;
	int			len_space;

	def_lensymbols(&len_symbols, &(*value));
	space = g_flags & 16 && !(g_flags & 1) ? '0' : ' ';
	len_space = g_width - len_symbols - len_sign(&(*value));
	putcycle(space, len_space, &(*amt));
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
	putcycle('0', len_zero, &(*amt));
}

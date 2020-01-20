/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:06:10 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/20 13:49:45 by jthuy            ###   ########.fr       */
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

void	put_charcycle(char symbol, int border, int *amt)
{
	int		i;

	i = 0;
	while (i < border)
	{
		put_char(symbol, NULL, &(*amt));
		i += 1;
	}
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

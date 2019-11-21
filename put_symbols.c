/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:06:10 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/21 18:38:50 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char symbol, const char **str, int *amount)
{
	write(1, &symbol, 1);
	*str += 1;
	*amount += 1;
}

int		put_freesmb(const char **str, int *amount)
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

void	put_abs(int value, char flags, int *amount)
{
	if (!(flags & 32))
	{
		if (value == -2147483648)
		{
			write(1, "2", 1);
			*amount += 1;
			put_abs(147483648, flags, &(*amount));
			return ;
		}
		if (value < 0)
		{
			put_abs((-1) * value, flags, &(*amount));
			return ;
		}
		if (value < 10)
		{
			value = value + 48;
			write(1, &value, 1);
			*amount += 1;
			return ;
		}
		put_abs(value / 10, flags, &(*amount));
		value = (value % 10) + 48;
		write(1, &value, 1);
		*amount += 1;
	}
}

void	put_uabs(unsigned int value, char flags, int *amount)
{
	if (flags & 32)
	{
		if (value < 10)
		{
			value = value + 48;
			write(1, &value, 1);
			*amount += 1;
			return ;
		}
		put_uabs(value / 10, flags, &(*amount));
		value = (value % 10) + 48;
		write(1, &value, 1);
		*amount += 1;
	}
}

void	put_sign(int value, char flags, int *amount)
{
	if (!(flags & 32))
	{
		if (value < 0)
		{
			write(1, "-", 1);
			*amount += 1;
			return ;
		}
		if (flags & 2)
		{
			write(1, "+", 1);
			*amount += 1;
			return ;
		}
		if (flags & 4)
		{
			write(1, " ", 1);
			*amount += 1;
			return ;
		}
	}
}

void	put_space(int len_space, char flags, int *amount)
{
	char	space;
	int		i;

	space = ' ';
	if (flags & 16 && !(flags & 1))
		space = '0';
	i = 0;
	while (i < len_space)
	{
		write(1, &space, 1);
		*amount += 1;
		i += 1;
	}
}

void	ft_putstr(char const *s, int *amount)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(1, s, 1);
		*amount += 1;
		s += 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:06:10 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/12 20:55:23 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_freesmb(const char **str, int *amount)
{
	while (**str != '%')
	{
		if (**str == '\0')
			return (0);
		write(1, *str, 1);
		*str += 1;
		*amount += 1;
		continue ;
	}
	*str += 1;
	return (1);
}

void	put_abs(int n, int *amount)
{
	if (n == -2147483648)
	{
		write(1, "2", 1);
		*amount += 1;
		put_abs(147483648, &(*amount));
		return ;
	}
	if (n < 0)
	{
		put_abs((-1) * n, &(*amount));
		return ;
	}
	if (n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
		*amount += 1;
		return ;
	}
	put_abs(n / 10, &(*amount));
	n = (n % 10) + 48;
	write(1, &n, 1);
	*amount += 1;
}

void	put_sign(int value_d, char flags, int *amount)
{
	if (value_d < 0)
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

void	put_space(int width, int value_d, char flags, int *amount)
{
	int		len_space;
	char	space;
	int		i;

	space = ' ';
	if (flags == 16 || flags == 18 || flags == 20)
		space = '0';
	len_space = width - len_numb_abc(value_d) - len_sign(value_d, flags);
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

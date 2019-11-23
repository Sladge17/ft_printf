/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:31:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/23 18:14:44 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_sign(int value, char flags, int *amount)
{
	if (!(flags & 32))
	{
		if (value < 0)
		{
			put_char('-', NULL, &(*amount));
			return ;
		}
		if (flags & 2)
		{
			put_char('+', NULL, &(*amount));
			return ;
		}
		if (flags & 4)
		{
			put_char(' ', NULL, &(*amount));
			return ;
		}
	}
}

void	put_abs(int value, char flags, int *amount)
{
	if (!(flags & 32))
	{
		if (value == -2147483648)
		{
			put_char('2', NULL, &(*amount));
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
			put_char(value + 48, NULL, &(*amount));
			return ;
		}
		put_abs(value / 10, flags, &(*amount));
		put_char((value % 10) + 48, NULL, &(*amount));
	}
}

void	put_prefix(char flags, int *amount)
{
	if (flags & 8)
	{
		if (flags & 32)
		{
			put_char('0', NULL, &(*amount));
			return ;
		}
		if (flags & 64)
		{
			put_str("0x", &(*amount));
			return ;
		}
		if (flags & 128)
		{
			put_str("0X", &(*amount));
			return ;
		}
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
		put_char((value % 10) + 48, NULL, &(*amount));
	}
}

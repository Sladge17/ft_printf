/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:31:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/05 13:29:56 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_sign(void **value, unsigned int *flags, int *amount)
{
	if (*flags & 253952)
		return ;
	if ((int)(*value) < 0)
	{
		put_char('-', NULL, &(*amount));
		return ;
	}
	if (*flags & 2)
	{
		put_char('+', NULL, &(*amount));
		return ;
	}
	if (*flags & 4)
	{
		put_char(' ', NULL, &(*amount));
		return ;
	}
}

void	put_abs(int value, unsigned int *flags, int *amount)
{
	extern int	g_accuracy;

	if (*flags & 253952 || (*flags & 64 && g_accuracy == 0 && value == 0))
		return ;
	if (value == -2147483648)
	{
		put_char('2', NULL, &(*amount));
		put_abs(147483648, &(*flags), &(*amount));
		return ;
	}
	if (value < 0)
	{
		put_abs((-1) * value, &(*flags), &(*amount));
		return ;
	}
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_abs(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

void	put_prefix(void **value, unsigned int *flags, int *amount)
{
	if (*flags & 28672 || !(*flags & 8) || !*value)
		// || (*flags & 8 && !*value))
		return ;
	if (*flags & 32768)
	{
		write(1, "0", 1);
		*amount += 1;
		return ;
	}
	if (*flags & 65536)
	{
		write(1, "0x", 2);
		*amount += 2;
		return ;
	}
	if (*flags & 131072)
	{
		write(1, "0X", 2);
		*amount += 2;
		return ;
	}
}

void	put_uabs(unsigned int value, unsigned int *flags, int *amount)
{
	// if (!(*flags & 8192))
	if (*flags & 20480 || (*flags & 229376 && value))
		return ;
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_uabs(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

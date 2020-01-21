/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_abs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:22:37 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/21 17:32:54 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_abs(void **value, int *amt)
{
	extern int		g_flags;
	extern int		g_accuracy;

	if (g_flags & 778240 || (g_flags & 64 && g_accuracy == 0 && !(*value)))
		return ;
	if (g_flags & 128)
	{
		put_abs_short((short)(*value), amt);
		return ;
	}
	if (g_flags & 256)
	{
		put_abs_char((char)(*value), amt);
		return ;
	}
	if (g_flags & 1536)
	{
		put_abs_lint((long int)(*value), amt);
		return ;
	}
	put_abs_int((int)(*value), amt);
}

void	put_abs_int(int value, int *amt)
{
	if (value == -2147483648)
	{
		put_char('2', NULL, amt);
		put_uabs_lint(147483648, amt);
		return ;
	}
	if (value < 0)
	{
		put_uabs_lint((-1) * value, amt);
		return ;
	}
	put_uabs_lint(value, amt);
}

void	put_abs_short(short value, int *amt)
{
	if (value == -32768)
	{
		put_char('3', NULL, amt);
		put_uabs_lint(2768, amt);
		return ;
	}
	if (value < 0)
	{
		put_uabs_lint((-1) * value, amt);
		return ;
	}
	put_uabs_lint(value, amt);
}

void	put_abs_char(char value, int *amt)
{
	if (value == -128)
	{
		put_char('1', NULL, amt);
		put_uabs_lint(28, amt);
		return ;
	}
	if (value < 0)
	{
		put_uabs_lint((-1) * value, amt);
		return ;
	}
	put_uabs_lint(value, amt);
}

void	put_abs_lint(long int value, int *amt)
{
	if ((unsigned long int)value == 9223372036854775808UL)
	{
		put_char('9', NULL, amt);
		put_uabs_lint(223372036854775808, amt);
		return ;
	}
	if (value < 0)
	{
		put_uabs_lint((-1) * value, amt);
		return ;
	}
	put_uabs_lint(value, amt);
}

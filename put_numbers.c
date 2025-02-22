/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:31:02 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/21 17:34:32 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_sign(void **value, int *amt)
{
	extern int	g_flags;

	if (g_flags & 778240)
		return ;
	if (((g_flags & 128 && (short)(*value) < 0)
		|| (g_flags & 256 && (char)(*value) < 0)
		|| (g_flags & 1536 && (long int)(*value) < 0))
		|| (!(g_flags & 3968) && (int)(*value) < 0))
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

void	put_prefix(void **value, int *amt)
{
	extern int	g_flags;
	extern int	g_accuracy;

	if (!(g_flags & 753666) || (g_flags & 229376 && !(g_flags & 8))
		|| (g_flags & 196608 && g_flags & 8 && !(*value))
		|| (g_flags & 32768 && g_flags & 8 && !(g_flags & 64) && !(*value)))
		return ;
	if (g_flags & 32768)
	{
		write(1, "0", 1);
		*amt += 1;
		return ;
	}
	if (g_flags & 589824)
	{
		write(1, "0x", 2);
		*amt += 2;
		return ;
	}
	if (g_flags & 131072)
	{
		write(1, "0X", 2);
		*amt += 2;
		return ;
	}
}

void	put_uabs(void **value, int *amt, int *g_flags)
{
	if (*g_flags & 20480
		|| (*g_flags & 64 && !(g_accuracy) && !(*g_flags & 1048576))
		|| (*g_flags & 229376 && *value) || (*g_flags & 524288 && *value))
		return ;
	if (*g_flags & 524288 && !(*value))
	{
		put_char('0', NULL, amt);
		return ;
	}
	if (*g_flags & 128)
	{
		put_uabs_lint((unsigned short)(*value), amt);
		return ;
	}
	if (*g_flags & 256)
	{
		put_uabs_lint((unsigned char)(*value), amt);
		return ;
	}
	if (*g_flags & 1536 || *g_flags & 1048576)
	{
		put_uabs_lint((unsigned long int)(*value), amt);
		return ;
	}
	put_uabs_lint((unsigned int)(*value), amt);
}

void	put_uabs_lint(unsigned long int value, int *amt)
{
	if (value < 10)
	{
		put_char(value + 48, NULL, amt);
		return ;
	}
	put_uabs_lint(value / 10, amt);
	put_char((value % 10) + 48, NULL, amt);
}

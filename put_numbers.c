/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:31:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/09 13:50:14 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_sign(void **value, unsigned int *flags, int *amount)
{
	if (*flags & 778240)
		return ;
	if ((!(*flags & 3968) && (int)(*value) < 0)
		|| (*flags & 128 && (short)(*value) < 0)
		|| (*flags & 256 && (char)(*value) < 0)
		|| (*flags & 1536 && (long int)(*value) < 0))
		// || (*flags & 512 && (long int)(*value) < 0)
		// || (*flags & 1024 && (long long int)(*value) < 0))
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

void	put_abs(void **value, unsigned int *flags, int *amount)
{
	extern int		g_accuracy;

	if (*flags & 778240 || (*flags & 64 && g_accuracy == 0 && !(*value)))
		return ;
	if (*flags & 128)
	{
		put_abs_short((short)(*value), &(*amount));
		return ;
	}
	if (*flags & 256)
	{
		put_abs_char((char)(*value), &(*amount));
		return ;
	}
	if (*flags & 1536)
	{
		put_abs_lint((long int)(*value), &(*amount));
		return ;
	}
	// if (*flags & 512)
	// {
	// 	put_abs_lint((long int)(*value), &(*amount));
	// 	return ;
	// }
	// if (*flags & 1024)
	// {
	// 	put_abs_llint((long long int)(*value), &(*amount));
	// 	return ;
	// }
	put_abs_int((int)(*value), &(*amount));
}

void	put_abs_int(int value, int *amount)
{
	if (value == -2147483648)
	{
		put_char('2', NULL, &(*amount));
		// put_uabs_llint(147483648, &(*amount));
		put_uabs_lint(147483648, &(*amount));
		return ;
	}
	if (value < 0)
	{
		// put_uabs_llint((-1) * value, &(*amount));
		put_uabs_lint((-1) * value, &(*amount));
		return ;
	}
	// put_uabs_llint(value, &(*amount));
	put_uabs_lint(value, &(*amount));
}

void	put_abs_short(short value, int *amount)
{
	if (value == -32768)
	{
		put_char('3', NULL, &(*amount));
		// put_uabs_llint(2768, &(*amount));
		put_uabs_lint(2768, &(*amount));
		return ;
	}
	if (value < 0)
	{
		// put_uabs_llint((-1) * value, &(*amount));
		put_uabs_lint((-1) * value, &(*amount));
		return ;
	}
	// put_uabs_llint(value, &(*amount));
	put_uabs_lint(value, &(*amount));
}

void	put_abs_char(char value, int *amount)
{
	if (value == -128)
	{
		put_char('1', NULL, &(*amount));
		// put_uabs_llint(28, &(*amount));
		put_uabs_lint(28, &(*amount));
		return ;
	}
	if (value < 0)
	{
		// put_uabs_llint((-1) * value, &(*amount));
		put_uabs_lint((-1) * value, &(*amount));
		return ;
	}
	// put_uabs_llint(value, &(*amount));
	put_uabs_lint(value, &(*amount));
}

// void	put_abs_lint(long int value, int *amount)
// {
// 	if (value == -2147483648)
// 	{
// 		put_char('2', NULL, &(*amount));
// 		put_uabs_llint(147483648, &(*amount));
// 		return ;
// 	}
// 	if (value < 0)
// 	{
// 		put_uabs_llint((-1) * value, &(*amount));
// 		return ;
// 	}
// 	put_uabs_llint(value, &(*amount));
// }

// void	put_abs_llint(long long int value, int *amount)
// {
// 	if (value & 1LL << 63)
// 	{
// 		put_char('9', NULL, &(*amount));
// 		put_uabs_llint(223372036854775808, &(*amount));
// 		return ;
// 	}
// 	if (value < 0)
// 	{
// 		put_uabs_llint((-1) * value, &(*amount));
// 		return ;
// 	}
// 	put_uabs_llint(value, &(*amount));
// }

void	put_abs_lint(long int value, int *amount)
{
	// if (value & 1L << 63)
	if ((unsigned long int)value == 9223372036854775808UL)
	{
		put_char('9', NULL, &(*amount));
		// put_uabs_llint(223372036854775808, &(*amount));
		put_uabs_lint(223372036854775808, &(*amount));
		return ;
	}
	if (value < 0)
	{
		// put_uabs_llint((-1) * value, &(*amount));
		put_uabs_lint((-1) * value, &(*amount));
		return ;
	}
	// put_uabs_llint(value, &(*amount));
	put_uabs_lint(value, &(*amount));
}

void	put_prefix(void **value, unsigned int *flags, int *amount)
{
	if (*flags & 28672 || !(*flags & 524296) || (!*value && !(*flags & 524288)))
		// || (*flags & 8 && !*value))
		return ;
	if (*flags & 32768)
	{
		write(1, "0", 1);
		*amount += 1;
		return ;
	}
	if (*flags & 589824)
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

void	put_uabs(void **value, unsigned int *flags, int *amount)
{
	if (*flags & 524288 && !(*value))
	{
		put_char('0', NULL, &(*amount));
		return ;
	}
	if (*flags & 544768 || (*flags & 229376 && *value)
		|| (*flags & 196608 && *flags & 64 && !(*value))
		|| (*flags & 32768 && !(*flags & 8) && *flags & 64 && !(*value)))
		return ;
	if (*flags & 128)
	{
		// put_uabs_llint((unsigned short)(*value), &(*amount));
		put_uabs_lint((unsigned short)(*value), &(*amount));
		return ;
	}
	if (*flags & 256)
	{
		// put_uabs_llint((unsigned char)(*value), &(*amount));
		put_uabs_lint((unsigned char)(*value), &(*amount));
		return ;
		return ;
	}
	// if (*flags & 512)
	// {
	// 	put_uabs_llint((unsigned long int)(*value), &(*amount));
	// 	return ;
	// }
	// if (*flags & 1024)
	// {
	// 	put_uabs_llint((unsigned long long int)(*value), &(*amount));
	// 	return ;
	// }
	if (*flags & 1536)
	{
		put_uabs_lint((unsigned long int)(*value), &(*amount));
		return ;
	}
	// put_uabs_llint((unsigned int)(*value), &(*amount));
	put_uabs_lint((unsigned int)(*value), &(*amount));
}

// void	put_uabs_llint(unsigned long long int value, int *amount)
// {
// 	if (value < 10)
// 	{
// 		put_char(value + 48, NULL, &(*amount));
// 		return ;
// 	}
// 	put_uabs_llint(value / 10, &(*amount));
// 	put_char((value % 10) + 48, NULL, &(*amount));
// }

void	put_uabs_lint(unsigned long int value, int *amount)
{
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_uabs_lint(value / 10, &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

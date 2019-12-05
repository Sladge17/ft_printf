/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:31:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/05 18:24:50 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_sign(void **value, unsigned int *flags, int *amount)
{
	if (*flags & 253952)
		return ;
	if (!(*flags & 3968) && (int)(*value) < 0)
	{
		put_char('-', NULL, &(*amount));
		return ;
	}
	if (*flags & 128 && (short)(*value) < 0)
	{
		put_char('-', NULL, &(*amount));
		return ;
	}
	if (*flags & 256 && (char)(*value) < 0)
	{
		put_char('-', NULL, &(*amount));
		return ;
	}
	if (*flags & 512 && (long int)(*value) < 0)
	{
		put_char('-', NULL, &(*amount));
		return ;
	}
	if (*flags & 1024 && (long long int)(*value) < 0)
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

// void	put_abs(int value, unsigned int *flags, int *amount)
// {
// 	extern int	g_accuracy;

// 	if (*flags & 253952 || (*flags & 64 && g_accuracy == 0 && value == 0))
// 		return ;
// 	if (value == -2147483648)
// 	{
// 		put_char('2', NULL, &(*amount));
// 		put_abs(147483648, &(*flags), &(*amount));
// 		return ;
// 	}
// 	if (value < 0)
// 	{
// 		put_abs((-1) * value, &(*flags), &(*amount));
// 		return ;
// 	}
// 	if (value < 10)
// 	{
// 		put_char(value + 48, NULL, &(*amount));
// 		return ;
// 	}
// 	put_abs(value / 10, &(*flags), &(*amount));
// 	put_char((value % 10) + 48, NULL, &(*amount));
// }

void	put_abs(void **value, unsigned int *flags, int *amount)
{
	extern int		g_accuracy;
	
	if (*flags & 253952 || (*flags & 64 && g_accuracy == 0 && !(*value)))
		return ;
	if (!(*flags & 3968))
	{
		put_abs_int((int)(*value), &(*flags), &(*amount));
		return ;
	}
	if (*flags & 128)
	{
		put_abs_short((short)(*value), &(*flags), &(*amount));
		return ;
	}
	if (*flags & 256)
	{
		put_abs_char((char)(*value), &(*flags), &(*amount));
		return ;
	}
	if (*flags & 512)
	{
		put_abs_lint((long int)(*value), &(*flags), &(*amount));
		return ;
	}
	if (*flags & 1024)
	{
		put_abs_llint((long long int)(*value), &(*flags), &(*amount));
		return ;
	}
}


void	put_abs_int(int value, unsigned int *flags, int *amount)
{
	if (value == -2147483648)
	{
		put_char('2', NULL, &(*amount));
		put_abs_int(147483648, &(*flags), &(*amount));
		return ;
	}
	if (value < 0)
	{
		put_abs_int((-1) * value, &(*flags), &(*amount));
		return ;
	}
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_abs_int(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

void	put_abs_short(short value, unsigned int *flags, int *amount)
{
	if (value == -32768)
	{
		put_char('3', NULL, &(*amount));
		put_abs_short(2768, &(*flags), &(*amount));
		return ;
	}
	if (value < 0)
	{
		put_abs_short((-1) * value, &(*flags), &(*amount));
		return ;
	}
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_abs_short(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

void	put_abs_char(char value, unsigned int *flags, int *amount)
{
	if (value == -128)
	{
		put_char('1', NULL, &(*amount));
		put_abs_char(28, &(*flags), &(*amount));
		return ;
	}
	if (value < 0)
	{
		put_abs_char((-1) * value, &(*flags), &(*amount));
		return ;
	}
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_abs_char(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

void	put_abs_lint(long int value, unsigned int *flags, int *amount)
{
	if (value == -2147483648)
	{
		put_char('2', NULL, &(*amount));
		put_abs_lint(147483648, &(*flags), &(*amount));
		return ;
	}
	if (value < 0)
	{
		put_abs_lint((-1) * value, &(*flags), &(*amount));
		return ;
	}
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_abs_lint(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

void	put_abs_llint(long long int value, unsigned int *flags, int *amount)
{
	if (value == -9223372036854775808)
	{
		put_char('9', NULL, &(*amount));
		put_abs_llint(223372036854775808, &(*flags), &(*amount));
		return ;
	}
	if (value < 0)
	{
		put_abs_llint((-1) * value, &(*flags), &(*amount));
		return ;
	}
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_abs_llint(value / 10, &(*flags), &(*amount));
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

// void	put_uabs(unsigned int value, unsigned int *flags, int *amount)
// {
// 	if (*flags & 20480 || (*flags & 229376 && value)
// 		|| (*flags & 196608 && *flags & 64 && !value)
// 		|| (*flags & 32768 && !(*flags & 8) && *flags & 64 && !value))
// 		return ;
// 	if (value < 10)
// 	{
// 		put_char(value + 48, NULL, &(*amount));
// 		return ;
// 	}
// 	put_uabs(value / 10, &(*flags), &(*amount));
// 	put_char((value % 10) + 48, NULL, &(*amount));
// }

void	put_uabs(void **value, unsigned int *flags, int *amount)
{
	if (*flags & 20480 || (*flags & 229376 && *value)
		|| (*flags & 196608 && *flags & 64 && !(*value))
		|| (*flags & 32768 && !(*flags & 8) && *flags & 64 && !(*value)))
		return ;
	
	if (!(*flags & 3968))
	{
		put_uabs_int((int)(*value), &(*flags), &(*amount));
		return ;
	}
	if (*flags & 128)
	{
		put_uabs_short((short)(*value), &(*flags), &(*amount));
		return ;
	}
	if (*flags & 256)
	{
		put_uabs_char((char)(*value), &(*flags), &(*amount));
		return ;
	}
	if (*flags & 512)
	{
		put_uabs_lint((long int)(*value), &(*flags), &(*amount));
		return ;
	}
	if (*flags & 1024)
	{
		put_uabs_llint((long long int)(*value), &(*flags), &(*amount));
		return ;
	}
}

void	put_uabs_int(unsigned int value, unsigned int *flags, int *amount)
{
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_uabs_int(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

void	put_uabs_short(unsigned short value, unsigned int *flags, int *amount)
{
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_uabs_short(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

void	put_uabs_char(unsigned char value, unsigned int *flags, int *amount)
{
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_uabs_char(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

void	put_uabs_lint(unsigned long int value, unsigned int *flags, int *amount)
{
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_uabs_lint(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

void	put_uabs_llint(unsigned long long int value, unsigned int *flags, int *amount)
{
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amount));
		return ;
	}
	put_uabs_llint(value / 10, &(*flags), &(*amount));
	put_char((value % 10) + 48, NULL, &(*amount));
}

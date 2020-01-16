/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:31:02 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/16 17:34:07 by jthuy            ###   ########.fr       */
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
		put_char('-', NULL, &(*amt));
		return ;
	}
	if (g_flags & 2)
	{
		put_char('+', NULL, &(*amt));
		return ;
	}
	if (g_flags & 4)
	{
		put_char(' ', NULL, &(*amt));
		return ;
	}
}

// void	put_sign_f(long double *value_f, int *flags, int *amt)
// {
// 	if (*value_f < 0)
// 	{
// 		put_char('-', NULL, &(*amt));
// 		return ;
// 	}
// 	if (*flags & 2)
// 	{
// 		put_char('+', NULL, &(*amt));
// 		return ;
// 	}
// 	if (*flags & 4)
// 	{
// 		put_char(' ', NULL, &(*amt));
// 		return ;
// 	}
// }

void	put_abs(void **value, int *amt)
{
	extern int		g_flags;
	extern int		g_accuracy;

	if (g_flags & 778240 || (g_flags & 64 && g_accuracy == 0 && !(*value)))
		return ;
	if (g_flags & 128)
	{
		put_abs_short((short)(*value), &(*amt));
		return ;
	}
	if (g_flags & 256)
	{
		put_abs_char((char)(*value), &(*amt));
		return ;
	}
	if (g_flags & 1536)
	{
		put_abs_lint((long int)(*value), &(*amt));
		return ;
	}
	// if (*flags & 512)
	// {
	// 	put_abs_lint((long int)(*value), &(*amt));
	// 	return ;
	// }
	// if (*flags & 1024)
	// {
	// 	put_abs_llint((long long int)(*value), &(*amt));
	// 	return ;
	// }
	put_abs_int((int)(*value), &(*amt));
}

void	put_abs_int(int value, int *amt)
{
	if (value == -2147483648)
	{
		put_char('2', NULL, &(*amt));
		// put_uabs_llint(147483648, &(*amt));
		put_uabs_lint(147483648, &(*amt));
		return ;
	}
	if (value < 0)
	{
		// put_uabs_llint((-1) * value, &(*amt));
		put_uabs_lint((-1) * value, &(*amt));
		return ;
	}
	// put_uabs_llint(value, &(*amt));
	put_uabs_lint(value, &(*amt));
}

void	put_abs_short(short value, int *amt)
{
	if (value == -32768)
	{
		put_char('3', NULL, &(*amt));
		// put_uabs_llint(2768, &(*amt));
		put_uabs_lint(2768, &(*amt));
		return ;
	}
	if (value < 0)
	{
		// put_uabs_llint((-1) * value, &(*amt));
		put_uabs_lint((-1) * value, &(*amt));
		return ;
	}
	// put_uabs_llint(value, &(*amt));
	put_uabs_lint(value, &(*amt));
}

void	put_abs_char(char value, int *amt)
{
	if (value == -128)
	{
		put_char('1', NULL, &(*amt));
		// put_uabs_llint(28, &(*amt));
		put_uabs_lint(28, &(*amt));
		return ;
	}
	if (value < 0)
	{
		// put_uabs_llint((-1) * value, &(*amt));
		put_uabs_lint((-1) * value, &(*amt));
		return ;
	}
	// put_uabs_llint(value, &(*amt));
	put_uabs_lint(value, &(*amt));
}

// void	put_abs_lint(long int value, int *amt)
// {
// 	if (value == -2147483648)
// 	{
// 		put_char('2', NULL, &(*amt));
// 		put_uabs_llint(147483648, &(*amt));
// 		return ;
// 	}
// 	if (value < 0)
// 	{
// 		put_uabs_llint((-1) * value, &(*amt));
// 		return ;
// 	}
// 	put_uabs_llint(value, &(*amt));
// }

// void	put_abs_llint(long long int value, int *amt)
// {
// 	if (value & 1LL << 63)
// 	{
// 		put_char('9', NULL, &(*amt));
// 		put_uabs_llint(223372036854775808, &(*amt));
// 		return ;
// 	}
// 	if (value < 0)
// 	{
// 		put_uabs_llint((-1) * value, &(*amt));
// 		return ;
// 	}
// 	put_uabs_llint(value, &(*amt));
// }

void	put_abs_lint(long int value, int *amt)
{
	// if (value & 1L << 63)
	if ((unsigned long int)value == 9223372036854775808UL)
	{
		put_char('9', NULL, &(*amt));
		// put_uabs_llint(223372036854775808, &(*amt));
		put_uabs_lint(223372036854775808, &(*amt));
		return ;
	}
	if (value < 0)
	{
		// put_uabs_llint((-1) * value, &(*amt));
		put_uabs_lint((-1) * value, &(*amt));
		return ;
	}
	// put_uabs_llint(value, &(*amt));
	put_uabs_lint(value, &(*amt));
}

void	put_prefix(void **value, int *amt)
{
	// if (*flags & 28672 || !(*flags & 524296) || (!(*value) && !(*flags & 524288)))
	extern int	g_flags;
	extern int	g_accuracy;
	
	// if (!(*flags & 229376)
	// || (*flags & 229376 && !(*flags & 8) && *value)
	// || (*flags & 229376 && !(*flags & 8) && !(*value) && !(*flags & 64))
	// || (*flags & 229376 && *flags & 8 && !(*value) && !(*flags & 64))
	// || (*flags & 229376 && *flags & 64 && !g_accuracy && *value)
	// )

	// if (!(*flags & 229376)
	// || (*flags & 229376 && !(*flags & 8))
	// || (*flags & 229376 && *flags & 8 && !(*value))
	// // || (*flags & 229376 && !(*flags & 8) && *value)
	// )

	if (!(g_flags & 753666)
	|| (g_flags & 229376 && !(g_flags & 8))
	// || (*flags & 229376 && *flags & 8 && !(*value))
	
	|| (g_flags & 196608 && g_flags & 8 && !(*value))
	|| (g_flags & 32768 && g_flags & 8 && !(g_flags & 64) && !(*value))
	
	// || (*flags & 229376 && !(*flags & 8) && *value)
	)
	
		// || (*flags & 8 && !*value))
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

void	put_uabs(void **value, int *amt)
{
	extern int	g_flags;
	
	// if (*flags & 544768 || (*flags & 64 && !(g_accuracy))
	if (g_flags & 20480 || (g_flags & 64 && !(g_accuracy) && !(g_flags & 1048576))
		|| (g_flags & 229376 && *value)
		// || (*flags & 196608 && *flags & 64 && !(*value))
		// || (*flags & 32768 && !(*flags & 8) && *flags & 64 && !(*value))
		|| (g_flags & 524288 && *value))
		return ;
	
	if (g_flags & 524288 && !(*value))
	{
		put_char('0', NULL, &(*amt));
		return ;
	}

	if (g_flags & 128)
	{
		// put_uabs_llint((unsigned short)(*value), &(*amt));
		put_uabs_lint((unsigned short)(*value), &(*amt));
		return ;
	}
	if (g_flags & 256)
	{
		// put_uabs_llint((unsigned char)(*value), &(*amt));
		put_uabs_lint((unsigned char)(*value), &(*amt));
		return ;
	}
	// if (*flags & 512)
	// {
	// 	put_uabs_llint((unsigned long int)(*value), &(*amt));
	// 	return ;
	// }
	// if (*flags & 1024)
	// {
	// 	put_uabs_llint((unsigned long long int)(*value), &(*amt));
	// 	return ;
	// }
	if (g_flags & 1536 || g_flags & 1048576) //
	{
		put_uabs_lint((unsigned long int)(*value), &(*amt));
		return ;
	}
	// put_uabs_llint((unsigned int)(*value), &(*amt));
	put_uabs_lint((unsigned int)(*value), &(*amt));
}

// void	put_uabs_llint(unsigned long long int value, int *amt)
// {
// 	if (value < 10)
// 	{
// 		put_char(value + 48, NULL, &(*amt));
// 		return ;
// 	}
// 	put_uabs_llint(value / 10, &(*amt));
// 	put_char((value % 10) + 48, NULL, &(*amt));
// }

void	put_uabs_lint(unsigned long int value, int *amt)
{
	if (value < 10)
	{
		put_char(value + 48, NULL, &(*amt));
		return ;
	}
	put_uabs_lint(value / 10, &(*amt));
	put_char((value % 10) + 48, NULL, &(*amt));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/23 12:37:54 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include "stdio.h"  ///  <-- DELL IT


// TEST TEST

// void	read_double(long double value)
// {
// 	void			*ptr;
// 	short			exp;
// 	unsigned long	mantissa;
// 	int				i;
// 	int				rez;
	
// 	rez = (int)value;
// 	while (value - rez != 0)
// 	{
// 		value *= 10;
// 		rez = (int)value;
// 		printf("%Lf\n", value);
// 	}
	
// 	ptr = &value;
// 	i = 64;
// 	exp = *((unsigned long *)ptr + 1);
// 	exp = exp & 32768 ? (exp ^ 32768) -16383 : exp - 16383;
// 	mantissa = *(unsigned long *)ptr;
	
// 	i = 64;
// 	while (mantissa && !(mantissa & 1UL))
// 	{
// 		mantissa >>= 1;
// 		i -= 1;
// 	}
// 	rez = 0;
// 	while (exp > 0)
// 	{
// 		if (mantissa & 1UL << (i - 1))
// 			rez = rez + (1 << exp);
// 		exp -= 1;
// 		i -= 1;
// 	}
// 	rez = mantissa & 1UL << (i - 1) ? rez + 1 : rez;
// 	exp -= 1;
// 	i -= 1;
	
// 	printf("rez = ");
// 	if (*((unsigned long *)ptr + 1) & 1UL << 15)
// 		printf("-");
// 	printf("%d.\n", rez);

// 	while (!(mantissa & 1UL << i))
// 	{
// 		exp -= 1;
// 		i -= 1;
// 	}
// 	printf("exp = %d\n", exp);
// 	printf("i = %d\n", i);

// 	rez = (int)value;
// 	printf("%d\n", rez);
// }

// void	read_double(long double value)
// {
// 	int		rez;
	
// 	if (value < 0)
// 	{
// 		printf("-");
// 		value = -value;
// 	}
	
// 	rez = (int)value;
// 	printf("%d.", rez);

// 	value = 10 * (value - rez);
// 	while ((rez = (int)(value)))
// 	{
// 		printf("%d", rez);
// 		value = 10 * (value - rez);
// 	}
// }

// void	read_double(double value)
// {
// 	int		rez;
	
// 	if (value < 0)
// 	{
// 		printf("-");
// 		value = -value;
// 	}
	
// 	rez = (int)value;
// 	printf("%d.", rez);

// 	value = 10 * (value - rez);
// 	while ((rez = (int)(value)))
// 	{
// 		printf("%d", rez);
// 		value = 10 * (value - rez);
// 	}
// }

void	shift_garbage(const char **str)
{
	while (1)
	{
		if (**str == '-' || **str == '+' || **str == ' ' || **str == '#'
			|| **str == '0' || **str == 'h' || **str == 'l' || **str == 'L'
			|| **str == 'j' || **str == 'z' || **str == 'Z' || **str == 'd'
			|| **str == 'i' || **str == 'u' || **str == 's' || **str == 'o'
			|| **str == 'x' || **str == 'X' || **str == 'c' || **str == 'p'
			|| **str == 'f' || **str == 'U' || **str == '%' || **str == '\0')
			break ;
		*str += 1;
	}
}

char	parsing(unsigned int *flags, const char **str)
{
	*flags = 0;
	check_flags(&(*flags), &(*str));
	def_width(&(*flags), &(*str));
	if (**str == '\0')
		return (0);
	check_flags(&(*flags), &(*str));
	def_accuracy(&(*flags), &(*str));
	shift_garbage(&(*str));
	check_flags(&(*flags), &(*str));
	if (!def_fasttype(&(*flags), &(*str)))
	{
		def_modifier(&(*flags), &(*str));
		check_flags(&(*flags), &(*str));
		def_type(&(*flags), &(*str));
	}
	if (((*flags & 112) == 112 && !(*flags & 15))
		|| (*flags & 233472 && (*flags & 80) == 80))
		*flags ^= 16;
	return (1);
}

char	exe_numstr(void **value, unsigned int *flags, const char **str, int *amt)
{
	if (!(*flags & 782336))
		return (0);
	conversion(&(*value), &(*flags));
	len_arg(&(*value), &(*flags));
	if (*flags & 32 && !(*flags & 17))
		put_space(&(*value), &(*flags), &(*amt));
	put_sign(&(*value), &(*flags), &(*amt));
	put_prefix(&(*value), &(*flags), &(*amt));
	put_zero(&(*value), &(*flags), &(*amt));
	if ((*flags & 48) == 48 && !(*flags & 1))
		put_space(&(*value), &(*flags), &(*amt));
	put_abs(&(*value), &(*flags), &(*amt));
	put_uabs(&(*value), &(*flags), &(*amt));
	put_str(*value, &(*flags), &(*amt));
	if ((*flags & 33) == 33)
		put_space(&(*value), &(*flags), &(*amt));
	*str += 1;
	return (1);
}

int		ft_printf(const char *str, ...)
{
	int				amount;
	va_list			args;
	unsigned int	flags;
	void			*value;
	double			value_f;

	amount = 0;
	va_start(args, str);
	while (*str)
	{
		if (!put_freesmb(&str, &amount))
			break ;
		if (check_lastfreesmb(&str, &amount))
			continue ;
		if (!parsing(&flags, &str))
			break ;

		if (*str != '%')
		{
			if ((flags & 1050624) == 1050624)
				value_f = va_arg(args, long double);
			else if (flags & 1048576)
				value_f = va_arg(args, double);
			else
				value = va_arg(args, void *);
		}

		// if (flags & 1048576)
		// {
		// 	int				unit;
		// 	unsigned long	remainder;
		// 	void			*ptr;
		// 	int 			i;

		// 	ptr = &unit;
			
		// 	if (value_real < 0)
		// 	{
		// 		put_char('-', NULL, &amount);
		// 		value_real = -value_real;
		// 	}
			
		// 	unit = (int)value_real;
		// 	put_uabs(ptr, &flags, &amount);
		// 	put_char('.', NULL, &amount);
			
		// 	remainder = 0;
		// 	i = 0;
		// 	while (i < 19)
		// 	{
		// 		value_real = 10 * (value_real - unit);
		// 		unit = (int)value_real;
		// 		remainder = (10 * remainder) + unit;
		// 		i += 1;
		// 	}
		// 	ptr = &remainder;
		// 	flags |= 1024;
		// 	while (remainder && !(remainder % 10))
		// 		remainder = remainder / 10;
		// 	put_uabs(ptr, &flags, &amount);
		// 	len_arg(ptr, &flags);
		// 	put_zero(ptr, &flags, &amount);
		// 	str += 1;
		// 	continue ;
		// }

		if (flags & 1048576)
		{
			int		unit;
			int		unit_rem;
			char	*remainder;
			void	*ptr;
			int 	i;
			extern int	g_accuracy;

			ptr = &unit;
			
			if (value_f < 0)
			{
				put_char('-', NULL, &amount);
				value_f = -value_f;
			}
			
			unit = (int)value_f;
			unit_rem = unit;
			
			if (!(flags & 64))
				g_accuracy = 6;
			remainder = (char *)malloc(sizeof(char) * (g_accuracy + 1));
			i = 0;
			while (i < g_accuracy + 1)
			{
				value_f = 10 * (value_f - unit_rem);
				unit_rem = (int)value_f;
				remainder[i] = unit_rem;
				i += 1;
			}

			// if (remainder[g_accuracy + 1] == 9)
			// 	remainder[g_accuracy] += 1;

			i = g_accuracy;

			if (i == 0 && remainder[i] > 4)
				unit += 1;
			
			if (remainder[i] > 4 && i)
			{
				remainder[i - 1] += 1;
				i -= 1;
			}
			
			while (remainder[i] > 9)
			{
				if (i == 0 && remainder[i] > 9)
					unit += 1;
				remainder[i] = 0;
				remainder[i - 1] += 1;
				i -= 1;
			}
			
			// while (remainder[i] > 5)
			// {
			// 	if (remainder[i] == 10)
			// 		remainder[i] = 0;
			// 	remainder[i - 1] += 1;
			// 	i -= 1;
			// }
			
			// i = 0;
			// while (i < g_accuracy)
			// {
			// 	if (remainder[i] == 10)
			// 		remainder[i] = 0;
			// 	i += 1;
			// }
			put_sign(ptr, &flags, &amount);
			put_uabs(ptr, &flags, &amount);
			if (g_accuracy || flags & 8)
				put_char('.', NULL, &amount);
			
			i = 0;
			while (i < g_accuracy)
			{
				put_char(remainder[i] + 48, NULL, &amount);
				i += 1;
			}
			str += 1;
			continue ;
		}

		
		// conversion(&value, &flags);
		// len_arg(&value, &flags);
		// if (flags & 782336)
		// {
		// 	conversion(&value, &flags);
		// 	len_arg(&value, &flags);
		// 	if (flags & 32 && !(flags & 17))
		// 		put_space(&value, &flags, &amount);
		// 	put_sign(&value, &flags, &amount);
		// 	put_prefix(&value, &flags, &amount);
		// 	put_zero(&value, &flags, &amount);
		// 	if ((flags & 48) == 48 && !(flags & 1))
		// 		put_space(&value, &flags, &amount);
		// 	put_abs(&value, &flags, &amount);
		// 	put_uabs(&value, &flags, &amount);
		// 	put_str(value, &flags, &amount);
		// 	if ((flags & 33) == 33)
		// 		put_space(&value, &flags, &amount);
		// 	str += 1;
		// 	continue ;
		// }
		if (exe_numstr(&value, &flags, &str, &amount))
			continue ;
		if (flags & 32)
		{
			len_arg(&value, &flags);
			if (!(flags & 1))
				put_space(&value, &flags, &amount);
			if (flags & 262144)
				put_char((char)value, &str, &amount);
			else
				put_char(*str, &str, &amount);
			if (flags & 1)
				put_space(&value, &flags, &amount);
			continue ;
		}
		if (flags & 262144)
		{
			put_char((char)value, &str, &amount);
			continue ;
		}
		if (*str != '\0')
			put_char(*str, &str, &amount);
	}
	va_end(args);
	return (amount);
}

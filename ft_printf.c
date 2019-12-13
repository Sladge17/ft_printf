/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/13 16:11:27 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "stdio.h"  ///  <-- DELL IT


// void	read_double(long double value)
// {
// 	void			*ptr;
// 	short			exp;
// 	unsigned long	mantissa;
// 	int				i;
// 	int				rez;

// 	ptr = &value;
// 	i = 64;
// 	while (i > 0)
// 	{
// 		if (*((unsigned long *)ptr) & (1UL << (i - 1)))
// 			printf("1");
// 		else
// 			printf("0");
// 		i -= 1;
// 	}
// 	// exp = *((unsigned long *)ptr + 1) << 1;
// 	// exp = (exp >> 1) - 16383;
// 	exp = *((unsigned long *)ptr + 1);
// 	exp = exp & 32768 ? (exp ^ 32768) -16383 : exp - 16383;
// 	printf("\nexp = %hu\n", exp);
// 	mantissa = *(unsigned long *)ptr;
// 	// printf("%lu\n", mantissa);
	
// 	i = 63;
// 	while (mantissa && !(mantissa & 1UL))
// 	{
// 		mantissa >>= 1;
// 		i -= 1;
// 	}
// 	// printf("%lu\n", mantissa);
// 	printf("%d\n", i);
// 	rez = 0;
// 	while (exp > 0)
// 	{
// 		if (mantissa & 1UL << i)
// 			rez = rez + (1 << exp);
// 		exp -= 1;
// 		i -= 1;
// 	}
// 	rez = mantissa & 1UL << i ? rez + 1 : rez;
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

void	read_double(long double value)
{
	int		rez;
	
	if (value < 0)
	{
		printf("-");
		value = -value;
	}
	
	rez = (int)value;
	printf("%d.", rez);

	value = 10 * (value - rez);
	while ((rez = (int)(value)))
	{
		printf("%d", rez);
		value = 10 * (value - rez);
	}
}

// void	read_double(double value)
// {
// 	int		i;
// 	int		j;
// 	void	*ptr;
// 	unsigned long	exp;
// 	unsigned long	mant;

// 	ptr = &value;

// 	i = 64;
// 	while (i > 0)
// 	{
// 		if (i == 63 || i == 52)
// 			printf("|");
// 		if (*(unsigned long *)ptr & (1L << (i - 1)))
// 			printf("1");
// 		else
// 			printf("0");
// 		i -= 1;
// 	}
// 	// exp = *(unsigned long *)ptr;
// 	// exp = exp >> 52;
// 	// if (exp & 2048)
// 	// 	exp = exp ^ 2048;
// 	// exp = exp - 1023;
// 	// printf("\n%lu\n", exp);
// 	exp = *(unsigned long *)ptr >> 52;
// 	exp = exp & 2048 ? (exp ^ 2048) - 1023 : exp - 1023;
// 	printf("\n%lu\n", exp);

// 	i = 0;
// 	mant = *(unsigned long *)ptr;
// 	while (!(mant & 1))
// 	{
// 		mant >>= 1;
// 		i += 1 ;
// 	}
// 	printf("\n%lu\n", mant);
// }

// void	read_double(long double value)
// {
// 	int		i;
// 	int		j;
// 	void	*ptr;
// 	unsigned long	exp;
// 	unsigned long	mant;

// 	ptr = &value;

// 	i = 64;
// 	while (i > 0)
// 	{
// 		// if (i == 63 || i == 52)
// 		// 	printf("|");
// 		if (*(unsigned long *)ptr & (1UL << (i - 1)))
// 			printf("1");
// 		else
// 			printf("0");
// 		i -= 1;
// 	}
	
// 	exp = *(unsigned long *)ptr >> 64;
// 	exp = exp & 2048 ? (exp ^ 2048) - 1023 : exp - 1023;
// 	printf("\n%lu\n", exp);

// 	// i = 0;
// 	// mant = *(unsigned long *)ptr;
// 	// while (!(mant & 1))
// 	// {
// 	// 	mant >>= 1;
// 	// 	i += 1 ;
// 	// }
// 	// printf("\n%lu\n", mant);
// }

int		ft_printf(const char *str, ...)
{
	int				amount;
	va_list			args;
	unsigned int	flags;
	void			*value;
	double			value_real;

	amount = 0;
	va_start(args, str);
	while (*str)
	{
		if (!put_freesmb(&str, &amount))
			break ;
		if (check_lastfreesmb(&str, &amount))
			continue ;
		// value = va_arg(args, void *);
		flags = 0;
		check_flags(&flags, &str);
		def_width(&flags, &str);
		check_flags(&flags, &str);
		def_accuracy(&flags, &str);
		
		
		// while (*str != '-' && *str != '+' && *str != ' ' && *str != '#'
		// 	&& *str != '0' && *str != 'h' && *str != 'l' && *str != 'L'
		// 	&& *str != 'j' && *str != 'z' && *str != 'U' && *str != 'd'
		// 	&& *str != 'i' && *str != 'u' && *str != 's' && *str != 'o'
		// 	&& *str != 'x' && *str != 'X' && *str != 'c' && *str != 'p' && *str != '\0'
		// 	&& *str != 'f' && *str != '%' && *str != 'Z')
		// 	str += 1;
		
		while (1)
		{
			if (*str == '-' || *str == '+' || *str == ' ' || *str == '#'
				|| *str == '0' || *str == 'h' || *str == 'l' || *str == 'L'
				|| *str == 'j' || *str == 'z' || *str == 'U' || *str == 'd'
				|| *str == 'i' || *str == 'u' || *str == 's' || *str == 'o'
				|| *str == 'x' || *str == 'X' || *str == 'c' || *str == 'p'
				|| *str == 'f' || *str == '\0' || *str == '%' || *str == 'Z')
				break ;
			str += 1;
		}
		
		check_flags(&flags, &str);
		
		if (!def_fasttype(&flags, &str))
		{
			def_modifier(&flags, &str);
			check_flags(&flags, &str);
			def_type(&flags, &str);
		}
		
		if ((flags & 112) == 112 && !(flags & 15))
			flags ^= 16;
		if (flags & 233472 && (flags & 80) == 80)
			flags ^= 16;
		
		
		// if (flags & 1048576)
		// {
		// 	value_real = va_arg(args, double);
		// 	read_double(value_real);
		// 	break ;
		// }
		// else
		// {
		// 	value = va_arg(args, void *);
		// }

		// if (flags & 1048576)
		// {
		// 	value_real = va_arg(args, double);
		// 	read_double(value_real);
		// 	break ;
		// }
		// else
		// {
		// 	value = va_arg(args, void *);
		// }

		if (flags & 1048576)
		{
			value_real = va_arg(args, double);
			read_double(value_real);
			break ;
		}
		else
		{
			value = va_arg(args, void *);
		}

		
		conversion(&flags, &value);
	
		if (flags & 782336)
		{
			if (flags & 16384 && !value)
			{
				write (1, "(null)", 6);
				amount += 6;
				str += 1;
				continue ;
			}
			if (flags & 32 && !(flags & 17))
				put_space(&value, &flags, &amount);
			put_sign(&value, &flags, &amount);
			put_zero(&value, &flags, &amount);
			put_prefix(&value, &flags, &amount);
			if (flags & 32 && flags & 16 && !(flags & 1))
				put_space(&value, &flags, &amount);


			// put_abs((int)value, &flags, &amount);
			put_abs(&value, &flags, &amount);
			
			// put_uabs((int)value, &flags, &amount);
			put_uabs(&value, &flags, &amount);
			put_str(value, &flags, &amount);
			if (flags & 32 && flags & 1)
				put_space(&value, &flags, &amount);
			str += 1;
			continue ;
		}

			
		if (flags & 32)
		{
			if (flags & 1)
			{
				if (flags & 262144)
					put_char((char)value, &str, &amount);
				else
					put_char(*str, &str, &amount);
				put_space(&value, &flags, &amount);
				continue ;
			}
			put_space(&value, &flags, &amount);
			if (flags & 262144)
				put_char((char)value, &str, &amount);
			else
				put_char(*str, &str, &amount);
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

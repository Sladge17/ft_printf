/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/09 12:27:30 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int				amount;
	va_list			args;
	unsigned int	flags;
	void			*value;

	amount = 0;
	va_start(args, str);
	while (*str)
	{
		if (!put_freesmb(&str, &amount))
			break ;
		if (check_lastfreesmb(&str, &amount))
			continue ;
		value = va_arg(args, void *);
		flags = 0;
		check_flags(&flags, &str);
		def_width(&flags, &str);
		check_flags(&flags, &str);
		def_accuracy(&flags, &str);
		
		
		// while (*str != '-' && *str != '+' && *str != ' ' && *str != '#'
		// 	&& *str != '0' && *str != 'h' && *str != 'l' && *str != 'L'
		// 	&& *str != 'j' && *str != 'z' && *str != 'U' && *str != 'd'
		// 	&& *str != 'i' && *str != 'u' && *str != 's' && *str != 'o'
		// 	&& *str != 'x' && *str != 'X' && *str != 'c' && *str == 'p' && *str != '\0'
		// 	&& *str != '%' && *str != 'Z')
		// 	str += 1;
		
		while (1)
		{
			if (*str == '-' || *str == '+' || *str == ' ' || *str == '#'
				|| *str == '0' || *str == 'h' || *str == 'l' || *str == 'L'
				|| *str == 'j' || *str == 'z' || *str == 'U' || *str == 'd'
				|| *str == 'i' || *str == 'u' || *str == 's' || *str == 'o'
				|| *str == 'x' || *str == 'X' || *str == 'c' || *str == 'p'
				|| *str == '\0' || *str == '%' || *str == 'Z')
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

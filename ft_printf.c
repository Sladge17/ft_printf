/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/03 17:05:53 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int		amount;
	va_list	args;
	short	flags;
	void	*value;

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
		if (flags & 64 && flags & 32 && flags & 16 && !(flags & 15))
			flags ^= 16;
		
		if (*str == 'o')
		{
			binto_oct(&value, *str);
			if (!value)
				break ;
			flags |= 256;
		}

		if (*str == 'x' || *str == 'X')
		{
			binto_hex(&value, *str);
			if (!value)
			// if (!value && !(flags & 64))
				break ;
			if (*str == 'x')
				flags |= 512;
			else
				flags |= 1024;
		}
		
		if (*str == 'u')
			flags |= 128;

		if (*str == 'd' || *str == 'i' || *str == 'u')
		{	
			if (flags & 32 && !(flags & 17))
				put_space(&str, &value, &flags, &amount);
			put_sign(&value, &flags, &amount);
			put_zero(&str, &value, &flags, &amount);   // NEED CHANGE
			if (flags & 32 && flags & 16 && !(flags & 1))
				put_space(&str, &value, &flags, &amount);
			put_abs((int)value, &flags, &amount);
			put_uabs((int)value, &flags, &amount);
			if (flags & 32 && flags & 1)
				put_space(&str, &value, &flags, &amount);
			str += 1;
			continue ;
		}

		if (*str == 's' || *str == 'o' || *str == 'x' || *str == 'X')
		{
			if (!value)
			// if (!value && !(flags & 64))
			{
				put_str( "(null)", &flags, &amount);
				str += 1;
				continue ;
			}
			if (flags & 32 && !(flags & 17))
				put_space(&str, &value, &flags, &amount);
			put_zero(&str, &value, &flags, &amount);
			put_prefix(&value, &flags, &amount);
			if (flags & 32 && flags & 16 && !(flags & 1))
				put_space(&str, &value, &flags, &amount);
			put_str(value, &flags, &amount);
			if (flags & 32 && flags & 1)
				put_space(&str, &value, &flags, &amount);
			str += 1;
			continue ;
		}
		
		if (*str == 'c')
		{
			if (flags & 32)
			{
				if (flags & 1)
				{
					put_char((char)value, &str, &amount);
					put_space(&str, &value, &flags, &amount);
					continue ;
				}
				put_space(&str, &value, &flags, &amount);
				put_char((char)value, &str, &amount);
				continue ;
			}
			put_char((char)value, &str, &amount);
			continue ;
		}
			
		if (flags & 32)
		{
			if (flags & 1)
			{
				put_char(*str, &str, &amount);
				put_space(&str, &value, &flags, &amount);
				continue ;
			}
			put_space(&str, &value, &flags, &amount);
			put_char(*str, &str, &amount);
			continue ;
		}
		if (*str != '\0')
			put_char(*str, &str, &amount);
	}
	va_end(args);
	return (amount);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/29 12:27:51 by jthuy            ###   ########.fr       */
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
				put_space(len_space(&str, &value, flags), flags, &amount);
			put_sign((int)value, flags, &amount);
			if (flags & 32 && flags & 16 && !(flags & 1))
				put_space(len_space(&str, &value, flags), flags, &amount);
			put_abs((int)value, flags, &amount);
			put_uabs((int)value, flags, &amount);
			if (flags & 32 && flags & 1)
				put_space(len_space(&str, &value, flags), flags, &amount);
			str += 1;
			continue ;
		}

		if (*str == 's' || *str == 'o' || *str == 'x' || *str == 'X')
		{
			if (!value)
			{
				put_str( "(null)", &amount);
				str += 1;
				continue ;
			}
			if (flags & 32 && !(flags & 17))
				put_space(len_space(&str, value, flags), flags, &amount);
			put_prefix(value, flags, &amount);
			if (flags & 32 && flags & 16 && !(flags & 1))
				put_space(len_space(&str, value, flags), flags, &amount);
			put_str(value, &amount);
			if (flags & 32 && flags & 1)
				put_space(len_space(&str, value, flags), flags, &amount);
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
					put_space(len_space(&str, &value, flags), flags, &amount);
					continue ;
				}
				put_space(len_space(&str, &value, flags), flags, &amount);
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
				put_space(len_space(&str, &value, flags), flags, &amount);
				continue ;
			}
			put_space(len_space(&str, &value, flags), flags, &amount);
			put_char(*str, &str, &amount);
			continue ;
		}
		if (*str != '\0')
			put_char(*str, &str, &amount);
	}
	va_end(args);
	return (amount);
}

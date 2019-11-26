/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/26 17:28:16 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int		amount;
	va_list	args;
	char	flags;
	int		width;
	void	*value;
	
	amount = 0;
	va_start(args, str);
	while (*str)
	{
		if (!put_freesmb(&str, &amount))
			break ;
		if (check_lastfreesmb(&str, &amount))
			continue ;

		flags = 0;
		check_flags(&flags, &str);
		width = def_width(&str);
		check_flags(&flags, &str);
		value = va_arg(args, void *);
		
		if (*str == 'o')
		{
			value = binto_oct((int)value);
			flags |= 32;
		}

		if (*str == 'x' || *str == 'X')
		{
			// value = binto_hex((int)value, *str);
			binto_hex(&value, *str);
			if (*str == 'x')
				flags |= 64;
			else
				flags |= 128;
		}
		
		if (*str == 'u')
			flags |= 32;

		if (*str == 'd' || *str == 'i' || flags & 32)
		{	
			if (width && !(flags & 17))
				put_space(len_space(width, &str, &value, flags), flags, &amount);
			put_sign((int)value, flags, &amount);
			if (width && flags & 16 && !(flags & 1))
				put_space(len_space(width, &str, &value, flags), flags, &amount);
			put_abs((int)value, flags, &amount);
			put_prefix(flags, &amount);
			put_uabs((int)value, flags, &amount);
			if (width && flags & 1)
				put_space(len_space(width, &str, &value, flags), flags, &amount);
			str += 1;
			continue ;
		}	
		
		if (*str == 's' || flags & 64 || flags & 128)
		{
			if (!value)
			{
				put_str( "(null)", &amount);
				str += 1;
				continue ;
			}
			if (width)
			{
				if (flags & 1)
				{
					put_prefix(flags, &amount);
					put_str(value, &amount);
					put_space(len_space(width, &str, value, flags), flags, &amount);
					str += 1;
					continue ;
				}
				put_space(len_space(width, &str, value, flags), flags, &amount);
				put_prefix(flags, &amount);
				put_str(value, &amount);
				str += 1;
				continue ;
			}
			put_prefix(flags, &amount);
			put_str(value, &amount);
			str += 1;
			continue ;
		}
		
		if (*str == 'c')
		{
			if (width)
			{
				if (flags & 1)
				{
					put_char((char)value, &str, &amount);
					put_space(len_space(width, &str, &value, flags), flags, &amount);
					continue ;
				}
				put_space(len_space(width, &str, &value, flags), flags, &amount);
				put_char((char)value, &str, &amount);
				continue ;
			}
			put_char((char)value, &str, &amount);
			continue ;
		}
			
		if (width)
		{
			if (flags & 1)
			{
				put_char(*str, &str, &amount);
				put_space(len_space(width, &str, &value, flags), flags, &amount);
				continue ;
			}
			put_space(len_space(width, &str, &value, flags), flags, &amount);
			put_char(*str, &str, &amount);
			continue ;
		}
		if (*str != '\0')
			put_char(*str, &str, &amount);
	}
	va_end(args);
	return (amount);
}

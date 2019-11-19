/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/19 19:59:42 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_prefix(int *amount, int value_d, char flags)
{
	if (value_d && flags & 8)
	{
		write(1, "0", 1);
		*amount += 1;
	}
}

int		ft_printf(const char *str, ...)
{
	int		amount;
	va_list	args;
	char	flags;
	int		width;
	
	int		value_d;
	char	*value_s;
	
	amount = 0;
	va_start(args, str);
	while (*str)
	{
		if(!put_freesmb(&str, &amount))
			break ;
			
		flags = check_flag(&str);
		width = def_width(&str);

		if (*str == 's')
		{
			value_s = va_arg(args, char *);
			ft_putstr(value_s, &amount);
			str += 1;
			continue ;
		}

		value_d = va_arg(args, int);
		
		if (*str == 'o')
		{
			value_d =binto_oct(value_d);
			flags |= 32;
			put_prefix(&amount, value_d, flags);
		}
		
		if (*str == 'u')
			flags |= 32;

		if (*str == 'd' || *str == 'i' || flags & 32)
		{		
			if (!width)
			{
				if (!(flags & 32))
				{
					put_sign(value_d, flags, &amount);
					put_abs(value_d, &amount);
				}
				if (flags & 32)
					put_uabs(value_d, &amount);
				str += 1;
				continue ;
			}

			if (flags & 1)
			{
				if (!(flags & 32))
				{
					put_sign(value_d, flags, &amount);
					put_abs(value_d, &amount);
					put_space(width, value_d, flags, &amount);
				}
				if (flags & 32)
				{
					put_uabs(value_d, &amount);
					put_space(width, value_d, flags, &amount);
				}
				str += 1;
				continue ;
			}
				
			if (flags & 16)
			{
				if (!(flags & 32))
				{
					put_sign(value_d, flags, &amount);
					put_space(width, value_d, flags, &amount);
					put_abs(value_d, &amount);
				}
				if (flags & 32)
				{
					put_space(width, value_d, flags, &amount);
					put_uabs(value_d, &amount);
				}
				str += 1;
				continue ;
			}
			
			if (!(flags & 32))
			{
				put_space(width, value_d, flags, &amount);
				put_sign(value_d, flags, &amount);
				put_abs(value_d, &amount);
			}
			if (flags & 32)
			{
				put_space(width, value_d, flags, &amount);
				put_uabs(value_d, &amount);
			}
			str += 1;
		}	
		
		if (*str == 'c')
		{
			if (width)
			{
				if (flags & 1)
				{
					put_char(value_d, &str, &amount);
					put_space(width, 1, flags, &amount);
					continue ;
				}
				put_space(width, 1, flags, &amount);
				put_char(value_d, &str, &amount);
				continue ;
			}
			put_char(value_d, &str, &amount);
			continue ;
		}
			
		// if (*str != '\0')
		// {
			if (width)
			{
				if (flags & 1)
				{
					put_char(*str, &str, &amount);
					put_space(width, 1, flags, &amount);
					continue ;
				}
				put_space(width, 1, flags, &amount);
				put_char(*str, &str, &amount);
				continue ;
			}
			put_char(*str, &str, &amount);
			continue ;
		// }
	}
	va_end(args);
	return (amount);
}

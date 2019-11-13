/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/13 17:11:31 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

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

		if (*str == 'u')
			flags |= 32;

		if (*str == 'd' || *str == 'i' || *str == 'u')
		{		
			value_d = va_arg(args, int);
			
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
			value_d = va_arg(args, int);
			write(1, &value_d, 1);
			str += 1;
			amount += 1;
			continue ;
		}
			
		if (*str == 's')
		{
			value_s = va_arg(args, char *);
			ft_putstr(value_s, &amount);
			str += 1;
			continue ;
		}
		if (*str == '%')
		{
			write(1, "%", 1);
			str += 1;
			amount += 1;
			continue ;
		}
	}
	va_end(args);
	return (amount);
}

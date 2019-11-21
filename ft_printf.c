/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/21 18:45:20 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_prefix(int value, char flags, int *amount)
{
	if (flags & 32)
	{
		if (flags & 8)
		{
			write(1, "0", 1);
			*amount += 1;
		}
	}
}

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
		if(!put_freesmb(&str, &amount))
			break ;
			
		flags = check_flags(&str);
		width = def_width(&str);
		value = va_arg(args, void *);

		if (*str == 's')
		{
			if (!value)
			{
				write(1, "(null)", 6);
				amount += 6;
				str += 1;
				continue ;
			}
			if (width)
			{
				if (flags & 1)
				{
					ft_putstr(value, &amount);
					put_space(len_space(width, &str, value, flags), flags, &amount);
					continue ;
				}
				put_space(len_space(width, &str, value, flags), flags, &amount);
				ft_putstr(value, &amount);
				str += 1;
				continue ;
			}
			ft_putstr(value, &amount);
			str += 1;
			continue ;
		}
		
		if (*str == 'o')
		{
			value =binto_oct((int)value);
			flags |= 32;
		}
		
		if (*str == 'u')
			flags |= 32;

		if (*str == 'd' || *str == 'i' || flags & 32)
		{		
			if (!width)
			{
				put_sign((int)value, flags, &amount);
				put_abs((int)value, flags, &amount);
				put_prefix((int)value, flags, &amount);
				put_uabs((int)value, flags, &amount);
				// if (!(flags & 32))
				// {
				// 	put_sign((int)value, flags, &amount);
				// 	// put_abs((int)value, &amount);
				// 	put_abs((int)value, flags, &amount);
				// }
				// if (flags & 32)
				// {
				// 	// put_prefix(&amount, flags);
				// 	// put_uabs((int)value, &amount);
				// 	put_prefix((int)value, flags, &amount);
				// 	put_uabs((int)value, flags, &amount);
				// }
				str += 1;
				continue ;
			}

			if (flags & 1)
			{
				// if (!(flags & 32))
				// {
				// 	put_sign((int)value, flags, &amount);
				// 	// put_abs((int)value, &amount);
				// 	put_abs((int)value, flags, &amount);
				// 	put_space(len_space(width, &str, &value, flags), flags, &amount);
				// }
				// if (flags & 32)
				// {
				// 	// put_prefix(&amount, flags);
				// 	// put_uabs((int)value, &amount);
				// 	put_prefix((int)value, flags, &amount);
				// 	put_uabs((int)value, flags, &amount);
				// 	put_space(len_space(width, &str, &value, flags), flags, &amount);
				// }
				put_sign((int)value, flags, &amount);
				put_abs((int)value, flags, &amount);
				put_prefix((int)value, flags, &amount);
				put_uabs((int)value, flags, &amount);
				put_space(len_space(width, &str, &value, flags), flags, &amount);
				str += 1;
				continue ;
			}
				
			if (flags & 16)
			{
				// if (!(flags & 32))
				// {
				// 	put_sign((int)value, flags, &amount);
				// 	put_space(len_space(width, &str, &value, flags), flags, &amount);
				// 	// put_abs((int)value, &amount);
				// 	put_abs((int)value, flags, &amount);
				// }
				// if (flags & 32)
				// {
				// 	put_space(len_space(width, &str, &value, flags), flags, &amount);
				// 	// put_prefix(&amount, flags);
				// 	// put_uabs((int)value, &amount);
				// 	put_prefix((int)value, flags, &amount);
				// 	put_uabs((int)value, flags, &amount);
				// }
				put_sign((int)value, flags, &amount);
				put_space(len_space(width, &str, &value, flags), flags, &amount);
				put_abs((int)value, flags, &amount);
				put_prefix((int)value, flags, &amount);
				put_uabs((int)value, flags, &amount);
				str += 1;
				continue ;
			}
			
			// if (!(flags & 32))
			// {
			// 	put_space(len_space(width, &str, &value, flags), flags, &amount);
			// 	put_sign((int)value, flags, &amount);
			// 	// put_abs((int)value, &amount);
			// 	put_abs((int)value, flags, &amount);
			// }
			// if (flags & 32)
			// {
			// 	put_space(len_space(width, &str, &value, flags), flags, &amount);
			// 	// put_prefix(&amount, flags);
			// 	// put_uabs((int)value, &amount);
			// 	put_prefix((int)value, flags, &amount);
			// 	put_uabs((int)value, flags, &amount);
				
			// }
			put_space(len_space(width, &str, &value, flags), flags, &amount);
			put_sign((int)value, flags, &amount);
			put_abs((int)value, flags, &amount);
			put_prefix((int)value, flags, &amount);
			put_uabs((int)value, flags, &amount);
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
		put_char(*str, &str, &amount);
	}
	va_end(args);
	return (amount);
}

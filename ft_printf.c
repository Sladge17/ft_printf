/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/25 18:20:17 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		check_lastfreesmb(const char **str, int *amount)
// {
// 	int		i;

// 	if (**str != ' ')
// 		return (0);
// 	*str += 1;
// 	i = 1;
// 	if (**str == '\0')
// 		return (0);
// 	while (**str == ' ')
// 	{
// 		*str += 1;
// 		i += 1;
// 	}
// 	if (**str == 'h' || **str == 'l' || **str == 'L')
// 	{
// 		*str += 1;
// 		return (0);
// 	}
// 	if (**str == '-' || **str == '+'|| **str == '#' || **str == '0' 
// 		|| **str == 'd' || **str == 'i' || **str == 'u' || **str == 'o'
// 		|| **str == 'x' || **str == 'X' || **str == 'c')
// 	{
// 		*str -= i;
// 		return (0);
// 	}
// 	put_char(**str, &(*str), &(*amount));
// 	return (1);
// }

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
			if ((int)value < 0)
				value = binto_uhex((unsigned int)value, *str);
			else
				value = binto_hex((int)value, *str);
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

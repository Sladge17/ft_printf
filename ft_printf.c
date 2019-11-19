/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/19 17:29:36 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		binto_oct(int value_d)
{
	int		oct;
	int		bitmask;
	int		i;
	int		factor;

	bitmask = 1;
	bitmask <<= def_bitborder(value_d);
	oct = 0;
	while (bitmask)
	{
		factor = 0;
		i = 0;
		while (i < 3)  // <-- need change for hex
		{
			if (value_d & bitmask)
				factor += two_inpower(2 - i);
			bitmask >>= 1;
			i += 1;
		}
		oct = oct * 10 + factor;
	}
	return (oct);
}

int		def_bitborder(int value_d)
{
	int		bitborder;
	int		bitmask;
	int		i;

	bitmask = 1;
	i = 0;
	while (i < 32)
	{
		if (value_d & bitmask)
			bitborder = i;
		i += 1;
		bitmask <<= 1;
	}
	while ((bitborder + 1) % 3)  // <-- need change for hex
		bitborder += 1;
	return (bitborder);
}

int		two_inpower(int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (2);
	return (two_inpower(power - 1) * 2);
}

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
			
		if (*str != '\0')
		{
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
		}
	}
	va_end(args);
	return (amount);
}

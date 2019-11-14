/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/14 20:33:54 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		two_inpower(int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (2);
	return (two_inpower(power - 1) * 2);
}

int		ppower(int number, int power)
{
	if (power == 0)
		return (1);
	if (number == 0)
		return (0);
	if (power == 1)
		return (number);
	return (ppower(number, power - 1) * number);
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

		
		
		if (*str == 'o')
		{
			int				len;
			unsigned int	mask;
			int		i;
			int		rez;
			
			value_d = va_arg(args, int);
			len = len_numb_uabc(value_d);
			printf("\n\nlen = %d\n", len);
			
			mask = 1;
			i = 0;
			while (!(mask & 2147483648))
			{
				if (value_d & mask)
				{
					rez = i;
				}
				i += 1;
				mask <<= 1;
			}
			if (value_d & mask)
				{
					rez = i;
				}
			while ((rez + 1) % 3)
			{
				rez += 1;
			}
			mask = 1;
			mask <<= rez;
			printf("\n\nmask = %d\n", mask);

			int		finrez;
			char	bit;
			
			finrez = 0;
			while (mask)
			{
				rez = 0;
				i = 0;
				while (i < 3)
				{
					if (value_d & mask)
						rez += two_inpower(2 - i);
					// bit = value_d & mask ? 1 : 0;
					// rez = rez + bit * ppower(2, (2 - i));
					mask >>= 1;
					i += 1;
				}
				finrez = finrez * 10 + rez;
			}
			printf("\n\nfinrez =  %d\n", finrez);

			exit (0);
		}



		
		
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

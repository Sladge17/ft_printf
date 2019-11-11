/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/11 20:01:15 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void		put_abs(int n, int *amount)
{
	if (n == -2147483648)
	{
		write(1, "2", 1);
		*amount += 1;
		put_abs(147483648, &(*amount));
		return ;
	}
	if (n < 0)
	{
		put_abs((-1) * n, &(*amount));
		return ;
	}
	if (n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
		*amount += 1;
		return ;
	}
	put_abs(n / 10, &(*amount));
	n = (n % 10) + 48;
	write(1, &n, 1);
	*amount += 1;
}

void	ft_putstr(char const *s, int *amount)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(1, s, 1);
		*amount += 1;
		s += 1;
	}
}

int		len_numb_abc(int value_d)
{
	int		len;

	len = 1;
	value_d = value_d < 0 ? (-1) * value_d : value_d;
	while (value_d > 9)
	{
		value_d /= 10;
		len += 1;
	}
	return (len);
}

int		len_sign(int value_d, char flags)
{
	if (value_d < 0)
		return (1);
	if (flags & 2 || flags & 4)
		return (1);
	return (0);
}

void	put_space(int width, int value_d, char flags, char c_space, int *amount)
{
	int		len_space;
	int		i;

	len_space = width - len_numb_abc(value_d) - len_sign(value_d, flags);
	i = 0;
	while (i < len_space)
	{
		write(1, &c_space, 1);
		*amount += 1;
		i +=1 ;
	}
}

void	put_sign(int value_d, char flags, int *amount)
{
	if (value_d < 0)
	{
		write(1, "-", 1);
		*amount += 1;
		return ;
	}
	if (flags & 2)
	{
		write(1, "+", 1);
		*amount += 1;
		return ;
	}
	if (flags & 4)
	{
		write(1, " ", 1);
		*amount += 1;
		return ;
	}
}


int		print_freesymbols(const char **str, int *amount)
{
	while (**str != '%')
	{
		if (**str == '\0')
			return (0);
		write(1, *str, 1);
		*str += 1;
		*amount += 1;
		continue ;
	}
	*str += 1;
	return (1);
}

int		ft_printf(const char *str, ...)
{
	int		amount;
	va_list	args;
	char	flags;
	int		width;
	int		len;
	
	int		value_d;
	char	*value_s;

	char	c_space;
	int		len_space;
	int		i;
	
	
	amount = 0;
	va_start(args, str);
	while (*str)
	{
		c_space = ' ';
		if(!print_freesymbols(&str, &amount))
			break ;
		
		flags = check_flag(&str);
		
		width = def_width(&str);
		

		if (*str == 'd' || *str == 'i')
		{
			c_space = ' ';
			
			value_d = va_arg(args, int);
			
			if (!width)
			{
				put_sign(value_d, flags, &amount);
				put_abs(value_d, &amount);
				str += 1;
				continue ;
			}
			
			// if (width)
			// {
				if (!flags || flags == 2 || flags == 4)
				{
					put_space(width, value_d, flags, ' ', &amount);
					put_sign(value_d, flags, &amount);
					put_abs(value_d, &amount);
					str += 1;
					continue ;
				}

				if (flags == 1 || flags == 17 || flags == 3 || flags == 7
					|| flags == 19 || flags == 23 || flags == 5 || flags == 21)
				{
					put_sign(value_d, flags, &amount);
					put_abs(value_d, &amount);
					put_space(width, value_d, flags, ' ', &amount);
					str += 1;
					continue ;
				}
					
				// if (flags == 2)
				// {
				// 	put_space(width, value_d, flags, ' ', &amount);
				// 	put_sign(value_d, flags, &amount);
				// 	put_abs(value_d, &amount);
				// 	str += 1;
				// 	continue ;
				// }

				// if (flags == 3 || flags == 7 || flags == 19 || flags == 23)
				// {
				// 	put_sign(value_d, flags, &amount);
				// 	put_abs(value_d, &amount);
				// 	put_space(width, value_d, flags, ' ', &amount);
				// 	str += 1;
				// 	continue ;
				// }
				
				// if (flags == 4)
				// {
				// 	put_space(width, value_d, flags, ' ', &amount);
				// 	put_sign(value_d, flags, &amount);
				// 	put_abs(value_d, &amount);
				// 	str += 1;
				// 	continue ;
				// }

				// if (flags == 5 || flags == 21)
				// {
				// 	put_sign(value_d, flags, &amount);
				// 	put_abs(value_d, &amount);
				// 	put_space(width, value_d, flags, ' ', &amount);
				// 	str += 1;
				// 	continue ;
				// }
					
				if (flags == 16 || flags == 18 || flags == 20)
				{
					put_sign(value_d, flags, &amount);
					put_space(width, value_d, flags, '0', &amount);
					put_abs(value_d, &amount);
					str += 1;
					continue ;
				}

				// if (flags == 18)
				// {
				// 	put_sign(value_d, flags, &amount);
				// 	put_space(width, value_d, flags, '0', &amount);
				// 	put_abs(value_d, &amount);
				// 	str += 1;
				// 	continue ;
				// }

				// if (flags == 20)
				// {
				// 	put_sign(value_d, flags, &amount);
				// 	put_space(width, value_d, flags, '0', &amount);
				// 	put_abs(value_d, &amount);
				// 	str += 1;
				// 	continue ;
				// }
			// }
			// put_sign(value_d, flags, &amount);
			// put_abs(value_d, &amount);
			// str += 1;
			// continue ;
			
		
		if (*str == 'c')
		{
			value_d = va_arg(args, int);
			write(1, &value_d, 1);
			str += 1;
			amount += 1;
			continue ;
		}
			
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

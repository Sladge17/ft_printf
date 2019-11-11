/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/11 16:55:45 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void		ft_putnbr(int n, int *amount)
{
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		*amount += 2;
		ft_putnbr(147483648, &(*amount));
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		*amount += 1;
		ft_putnbr((-1) * n, &(*amount));
		return ;
	}
	if (n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
		*amount += 1;
		return ;
	}
	ft_putnbr(n / 10, &(*amount));
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

int		len_sign(int flags, int value_d)
{
	if (value_d < 0)
		return (1);
	if (flags & 2 || flags & 4)
		return (1);
	return (0);
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
			
			if (width)
			{
				if (!flags)
				{
					// len = len_numb_abc(value_d);
					// len_space = width - len;
					len_space = width - len_numb_abc(value_d) - len_sign(flags, value_d);
					i = 0;
					while (i < len_space)
					{
						write(1, &c_space, 1);
						amount += 1;
						i +=1 ;
					}
					if (value_d < 0)
					{
						value_d = (-1) * value_d;
						amount += 1;
						write(1, "-", 1);
					}
					ft_putnbr(value_d, &amount);
					str += 1;
					continue ;
				}

				if (flags == 1 || flags == 17)
				{
					// len = len_numb_abc(value_d);
					// len_space = width - len;
					len_space = width - len_numb_abc(value_d) - len_sign(flags, value_d);
					i = 0;
					if (value_d < 0)
					{
						value_d = (-1) * value_d;
						write(1, "-", 1);
						amount += 1;
					}
					ft_putnbr(value_d, &amount);
					while (i < len_space)
					{
						write(1, &c_space, 1);
						amount += 1;
						i +=1 ;
					}
					str += 1;
					continue ;
				}
					
				if (flags == 2)
				{
					// len = len_numb_abc(value_d);
					// if (value_d >= 0)
					// 	len += 1;
					// len_space = width - len;
					len_space = width - len_numb_abc(value_d) - len_sign(flags, value_d);
					i = 0;
					while (i < len_space)
					{
						write(1, &c_space, 1);
						amount += 1;
						i +=1 ;
					}
					str += 1;
					if (value_d < 0)
					{
						value_d = (-1) * value_d;
						write(1, "-", 1);
						amount += 1;
					}
					else
					{
						write(1, "+", 1);
						amount += 1;
					}
					ft_putnbr(value_d, &amount);
					continue ;
				}

				if (flags == 3 || flags == 7 || flags == 19 || flags == 23)
				{
					// len = len_numb_abc(value_d);
					// if (value_d >= 0)
					// 	len += 1;
					// len_space = width - len;
					len_space = width - len_numb_abc(value_d) - len_sign(flags, value_d);
					if (value_d < 0)
					{
						value_d = (-1) * value_d;
						write(1, "-", 1);
						amount += 1;
					}
					else
					{
						write(1, "+", 1);
						amount += 1;
					}
					str += 1;
					ft_putnbr(value_d, &amount);
					i = 0;
					while (i < len_space)
					{
						write(1, &c_space, 1);
						amount += 1;
						i +=1 ;
					}
					continue ;
				}
				
				if (flags == 4)
				{
					// len = len_numb_abc(value_d);
					// if (value_d >= 0)
					// 	len += 1;
					// len_space = width - len;
					len_space = width - len_numb_abc(value_d) - len_sign(flags, value_d);
					i = 0;
					while (i < len_space)
					{
						write(1, &c_space, 1);
						amount += 1;
						i +=1 ;
					}
					str += 1;
					if (value_d < 0)
					{
						value_d = (-1) * value_d;
						write(1, "-", 1);
						amount += 1;
					}
					else
					{
						write(1, " ", 1);
						amount += 1;
					}
					ft_putnbr(value_d, &amount);
					continue ;
				}

				if (flags == 5 || flags == 21)
				{
					// len = len_numb_abc(value_d);
					// if (value_d >= 0)
					// 	len += 1;
					// len_space = width - len;
					len_space = width - len_numb_abc(value_d) - len_sign(flags, value_d);
					if (value_d < 0)
					{
						value_d = (-1) * value_d;
						write(1, "-", 1);
						amount += 1;
					}
					else
					{
						write(1, " ", 1);
						amount += 1;
					}
					str += 1;
					ft_putnbr(value_d, &amount);
					i = 0;
					while (i < len_space)
					{
						write(1, &c_space, 1);
						amount += 1;
						i +=1 ;
					}
					continue ;
				}
					
				if (flags == 16)
				{
					c_space = '0';
					// len = len_numb_abc(value_d);
					// len_space = width - len;
					len_space = width - len_numb_abc(value_d) - len_sign(flags, value_d);
					if (value_d < 0)
					{
						value_d = (-1) * value_d;
						write(1, "-", 1);
						amount += 1;
					}
					i = 0;
					while (i < len_space)
					{
						write(1, &c_space, 1);
						amount += 1;
						i +=1 ;
					}
					ft_putnbr(value_d, &amount);
					str += 1;
					continue ;
				}

				if (flags == 18)
				{
					c_space = '0';
					// len = len_numb_abc(value_d);
					// len_space = width - len;
					// if (value_d >= 0)
					// 	len_space -= 1;
					len_space = width - len_numb_abc(value_d) - len_sign(flags, value_d);
					if (value_d < 0)
					{
						value_d = (-1) * value_d;
						write(1, "-", 1);
						// amount += 1;
					}
					else
						write(1, "+", 1);
						amount += 1;
					
					i = 0;
					while (i < len_space)
					{
						write(1, &c_space, 1);
						amount += 1;
						i +=1 ;
					}
					ft_putnbr(value_d, &amount);
					str += 1;
					continue ;
				}

				if (flags == 20)
				{
					c_space = '0';
					// len = len_numb_abc(value_d);
					// len_space = width - len;
					len_space = width - len_numb_abc(value_d) - len_sign(flags, value_d);
					// if (value_d >= 0)
					// 	len_space -= 1;
					if (value_d < 0)
					{
						value_d = (-1) * value_d;
						write(1, "-", 1);
						amount += 1;
					}
					else
					{
						write(1, " ", 1);
						amount += 1;
					}
					
					i = 0;
					while (i < len_space)
					{
						write(1, &c_space, 1);
						amount += 1;
						i +=1 ;
					}
					ft_putnbr(value_d, &amount);
					str += 1;
					continue ;
				}
			}
			if ((flags == 2 || flags == 6) && value_d >= 0)
			{
				write(1, "+", 1);
				amount += 1;
			}
			if (flags == 4 && value_d >= 0)
			{
				write(1, " ", 1);
				amount += 1;
			}
			ft_putnbr(value_d, &amount);
			str += 1;
			continue ;
			
		
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

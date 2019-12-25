/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/25 13:47:13 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	shift_garbage(const char **str)
{
	while (1)
	{
		if (**str == '-' || **str == '+' || **str == ' ' || **str == '#'
			|| **str == '0' || **str == 'h' || **str == 'l' || **str == 'L'
			|| **str == 'j' || **str == 'z' || **str == 'Z' || **str == 'd'
			|| **str == 'i' || **str == 'u' || **str == 's' || **str == 'o'
			|| **str == 'x' || **str == 'X' || **str == 'c' || **str == 'p'
			|| **str == 'f' || **str == 'U' || **str == '%' || **str == '\0')
			break ;
		*str += 1;
	}
}

char	parsing(int *flags, const char **str)
{
	*flags = 0;
	check_flags(&(*flags), &(*str));
	def_width(&(*flags), &(*str));
	if (**str == '\0')
		return (0);
	check_flags(&(*flags), &(*str));
	def_accuracy(&(*flags), &(*str));
	shift_garbage(&(*str));
	check_flags(&(*flags), &(*str));
	if (!def_fasttype(&(*flags), &(*str)))
	{
		def_modifier(&(*flags), &(*str));
		check_flags(&(*flags), &(*str));
		def_type(&(*flags), &(*str));
	}
	if (((*flags & 112) == 112 && !(*flags & 15) && !(*flags & 1048576))
		|| (*flags & 233472 && (*flags & 80) == 80))
		*flags ^= 16;
	return (1);
}

char	exe_numstr(void **value, int *flags, const char **str, int *amt)
{
	if (!(*flags & 782336))
		return (0);
	conversion(&(*value), &(*flags));
	len_arg(&(*value), &(*flags));
	if (*flags & 32 && !(*flags & 17))
		put_space(&(*value), &(*flags), &(*amt));
	put_sign(&(*value), &(*flags), &(*amt));
	put_prefix(&(*value), &(*flags), &(*amt));
	put_zero(&(*value), &(*flags), &(*amt));
	if ((*flags & 48) == 48 && !(*flags & 1))
		put_space(&(*value), &(*flags), &(*amt));
	put_abs(&(*value), &(*flags), &(*amt));
	put_uabs(&(*value), &(*flags), &(*amt));
	put_str(*value, &(*flags), &(*amt));
	if ((*flags & 33) == 33)
		put_space(&(*value), &(*flags), &(*amt));
	*str += 1;
	return (1);
}

char	exe_flt(long double *val, int *flags, const char **str, int *amt)
{
	if (!(*flags & 1048576))
		return (0);
		
	long int	unit;
	long int	unit_rem;
	char		*remainder;
	void		*ptr;
	int 		i;
	extern int	g_accuracy;
	long double	value_fcp;
	
	
	if (!(*flags & 64))
		g_accuracy = 6;
	
	if (*flags & 32 && !(*flags & 1) && !(*flags & 16))
		put_space_f(&(*val), &(*flags), &(*amt));
	put_sign_f(&(*val), &(*flags), &(*amt));
		
	if ((*flags & 48) == 48 && !(*flags & 1))
		put_space_f(&(*val), &(*flags), &(*amt));
	
	
	value_fcp = *val;
	if (value_fcp < 0)
		value_fcp = -value_fcp;
	
	unit = (long int)value_fcp;
	unit_rem = unit;
	
	
	remainder = (char *)malloc(sizeof(char) * 21);
	if (!remainder)
		return (0);  // NEED FIX
	i = 0;
	while (i < 21)
	{
		value_fcp = 10 * (value_fcp - unit_rem);
		unit_rem = (char)value_fcp;
		remainder[i] = unit_rem;
		i += 1;
	}

	
	i = 19;
	if (remainder[i] > 4 && i != g_accuracy)
		remainder[i - 1] += 1;

	
	i -= 1;
	while (i > g_accuracy)
	{
		if (remainder[i] == 10)
			remainder[i - 1] += 1;
		i -= 1;
	}
	

	i = g_accuracy;
	if (i == 0 && remainder[i] > 4)
		unit += 1;
	if (remainder[i] > 4 && i)
	{
		remainder[i - 1] += 1;
		i -= 1;
	}
	while (remainder[i] > 9)
	{
		if (i == 0 && remainder[i] > 9)
			unit += 1;
		remainder[i] = 0;
		remainder[i - 1] += 1;
		i -= 1;
	}
	ptr = &unit;
	put_uabs(ptr, &(*flags), &(*amt));
	if (g_accuracy || *flags & 8)
		put_char('.', NULL, &(*amt));
	i = 0;
	while (i < g_accuracy)
	{
		put_char(remainder[i] + 48, NULL, &(*amt));
		i += 1;
	}
	free(remainder);
	
	if ((*flags & 33) == 33)
		put_space_f(&(*val), &(*flags), &(*amt));;
	
	*str += 1;
	return (1);
}

char	exe_wsymb(void **value, int *flags, const char **str, int *amt)
{
	if (!(*flags & 32))
		return (0);
	len_arg(&(*value), &(*flags));
	if (!(*flags & 1))
		put_space(&(*value), &(*flags), &(*amt));
	if (*flags & 262144)
		put_char((char)(*value), &(*str), &(*amt));
	else
		put_char(**str, &(*str), &(*amt));
	if (*flags & 1)
		put_space(&(*value), &(*flags), &(*amt));
	return (1);
}

void	exe(long double *vf, void **v, int *fl, const char **s, int *amt)
{
	if (exe_flt(&(*vf), &(*fl), &(*s), &(*amt)))
		return ;
	if (exe_numstr(&(*v), &(*fl), &(*s), &(*amt)))
		return ;
	if (exe_wsymb(&(*v), &(*fl), &(*s), &(*amt)))
		return ;
	if (*fl & 262144)
	{
		put_char((char)(*v), &(*s), &(*amt));
		return ;
	}
	if (**s != '\0')
		put_char(**s, &(*s), &(*amt));
}

void	intrp(va_list *args, long double *vf, void **v, int *fl, const char **s)
{
	if (**s == '%')
		return ;
	if ((*fl & 1050624) == 1050624)
	{
		*vf = va_arg(*args, long double);
		return ;
	}
	if (*fl & 1048576)
	{
		*vf = va_arg(*args, double);
		return ;
	}
	*v = va_arg(*args, void *);
}

int		ft_printf(const char *str, ...)
{
	int				amount;
	va_list			args;
	int				flags;
	void			*value;
	long double		value_f;

	amount = 0;
	va_start(args, str);
	while (*str)
	{
		if (!put_freesmb(&str, &amount))
			break ;
		if (check_lastfreesmb(&str, &amount))
			continue ;
		if (!parsing(&flags, &str))
			break ;
		intrp(&args, &value_f, &value, &flags, &str);
		exe(&value_f, &value, &flags, &str, &amount);
	}
	va_end(args);
	return (amount);
}

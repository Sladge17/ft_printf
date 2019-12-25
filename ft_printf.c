/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/25 16:35:37 by jthuy            ###   ########.fr       */
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

char	exe_numstr(void **value, int *flags, const char **str, int *amount)
{
	if (!(*flags & 782336))
		return (0);
	conversion(&(*value), &(*flags));
	len_arg(&(*value), &(*flags));
	if (*flags & 32 && !(*flags & 17))
		put_space(&(*value), &(*flags), &(*amount));
	put_sign(&(*value), &(*flags), &(*amount));
	put_prefix(&(*value), &(*flags), &(*amount));
	put_zero(&(*value), &(*flags), &(*amount));
	if ((*flags & 48) == 48 && !(*flags & 1))
		put_space(&(*value), &(*flags), &(*amount));
	put_abs(&(*value), &(*flags), &(*amount));
	put_uabs(&(*value), &(*flags), &(*amount));
	put_str(*value, &(*flags), &(*amount));
	if ((*flags & 33) == 33)
		put_space(&(*value), &(*flags), &(*amount));
	*str += 1;
	return (1);
}

void	def_remainder(char **remainder, long double value_f, long int unit)
{
	extern int	g_accuracy;
	int			i;
	
	// if (value_f < 0)
	// 	value_f = -value_f;
	value_f = value_f < 0 ? -value_f : value_f;
	*remainder = (char *)malloc(sizeof(char) * 21);
	// if (!(*remainder))
	// 	return (0);  // NEED FIX
	i = 0;
	while (i < 21)
	{
		value_f = 10 * (value_f - unit);
		unit = (char)value_f;
		(*remainder)[i] = unit;
		i += 1;
	}
	i = 19;
	if ((*remainder)[i] > 4 && i != g_accuracy)
		(*remainder)[i - 1] += 1;
	i -= 1;
	while (i > g_accuracy)
	{
		if ((*remainder)[i] == 10)
			(*remainder)[i - 1] += 1;
		i -= 1;
	}
}

char	exe_float(long double *value_f, int *flags, const char **str, int *amount)
{	
	long int	unit;
	// long int	unit_rem;
	char		*remainder;
	void		*ptr;
	int 		i;
	extern int	g_accuracy;
	// long double	value_fcp;

	if (!(*flags & 1048576))
		return (0);
	if (!(*flags & 64))
		g_accuracy = 6;
	if (*flags & 32 && !(*flags & 1) && !(*flags & 16))
		put_space_f(&(*value_f), &(*flags), &(*amount));
	put_sign_f(&(*value_f), &(*flags), &(*amount));
	if ((*flags & 48) == 48 && !(*flags & 1))
		put_space_f(&(*value_f), &(*flags), &(*amount));
	
	// value_fcp = *value_f;
	// if (value_fcp < 0)
	// 	value_fcp = -value_fcp;
	
	// unit = (long int)value_fcp;
	// unit_rem = unit;

	// unit = (long int)(*value_f);
	// if (unit < 0)
	// 	unit = -unit;
	unit = *value_f < 0 ? -(long int)(*value_f) : (long int)(*value_f);


	def_remainder(&remainder, *value_f, unit);
	
	// remainder = (char *)malloc(sizeof(char) * 21);
	// if (!remainder)
	// 	return (0);  // NEED FIX
	// i = 0;
	// while (i < 21)
	// {
	// 	value_fcp = 10 * (value_fcp - unit_rem);
	// 	unit_rem = (char)value_fcp;
	// 	remainder[i] = unit_rem;
	// 	i += 1;
	// }

	
	// i = 19;
	// if (remainder[i] > 4 && i != g_accuracy)
	// 	remainder[i - 1] += 1;

	
	// i -= 1;
	// while (i > g_accuracy)
	// {
	// 	if (remainder[i] == 10)
	// 		remainder[i - 1] += 1;
	// 	i -= 1;
	// }
	

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
		// if (i == 0 && remainder[i] > 9)
		if (!i)
		{
			unit += 1;
			remainder[i] = 0;
			// i -= 1;
			break ;
		}
		remainder[i] = 0;
		remainder[i - 1] += 1;
		i -= 1;
	}
	ptr = &unit;
	put_uabs(ptr, &(*flags), &(*amount));
	if (g_accuracy || *flags & 8)
		put_char('.', NULL, &(*amount));
	i = 0;
	while (i < g_accuracy)
	{
		put_char(remainder[i] + 48, NULL, &(*amount));
		i += 1;
	}
	free(remainder);
	
	if ((*flags & 33) == 33)
		put_space_f(&(*value_f), &(*flags), &(*amount));;
	
	*str += 1;
	return (1);
}

char	exe_wsymb(void **value, int *flags, const char **str, int *amount)
{
	if (!(*flags & 32))
		return (0);
	len_arg(&(*value), &(*flags));
	if (!(*flags & 1))
		put_space(&(*value), &(*flags), &(*amount));
	if (*flags & 262144)
		put_char((char)(*value), &(*str), &(*amount));
	else
		put_char(**str, &(*str), &(*amount));
	if (*flags & 1)
		put_space(&(*value), &(*flags), &(*amount));
	return (1);
}

void	exe_other(void **value, int *flags, const char **str, int *amount)
{
	if (exe_numstr(&(*value), &(*flags), &(*str), &(*amount)))
		return ;
	if (exe_wsymb(&(*value), &(*flags), &(*str), &(*amount)))
		return ;
	if (*flags & 262144)
	{
		put_char((char)(*value), &(*str), &(*amount));
		return ;
	}
	if (**str != '\0')
		put_char(**str, &(*str), &(*amount));
}

void	intrp(va_list *args, long double *value_f, void **value, int *flags)
{
	if ((*flags & 1050624) == 1050624)
	{
		*value_f = va_arg(*args, long double);
		return ;
	}
	if (*flags & 1048576)
	{
		*value_f = va_arg(*args, double);
		return ;
	}
	*value = va_arg(*args, void *);
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
		if (*str != '%')
			intrp(&args, &value_f, &value, &flags);
		if (exe_float(&value_f, &flags, &str, &amount))
			continue ;
		exe_other(&value, &flags, &str, &amount);
	}
	va_end(args);
	return (amount);
}

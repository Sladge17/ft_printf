/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/16 17:15:36 by jthuy            ###   ########.fr       */
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

char	parsing(const char **str, va_list *args)
{
	extern int	g_accuracy;
	extern int	g_flags;
	
	g_flags = 0;
	check_flags(&(*str));
	def_width(&(*str), &(*args));
	if (**str == '\0')
		return (0);
	check_flags(&(*str));
	def_accuracy(&(*str), &(*args));
	shift_garbage(&(*str));
	check_flags(&(*str));
	if (!def_fasttype(&(*str)))
	{
		def_modifier(&(*str));
		check_flags(&(*str));
		def_type(&(*str));
	}
	if (((g_flags & 112) == 112 && !(g_flags & 15) && !(g_flags & 1048576) && g_accuracy >= 0)
		|| (g_flags & 233472 && (g_flags & 80) == 80 && g_accuracy >= 0))
		g_flags ^= 16;
	if (g_accuracy < 0)
	// 	{
	// 		if (*flags & 16384)
	// 			g_accuracy = -g_accuracy;
	// 		else
	// 			g_accuracy = 0;
	// 	}
		g_accuracy = g_flags & 16384 ? -g_accuracy : 0;
	return (1);
}

char	exe_numstr(void **value, const char **str, int *amt)
{
	extern int	g_flags;
	
	if (!(g_flags & 782336))
		return (0);
	conversion(&(*value));
	len_arg(&(*value));
	if (g_flags & 32 && !(g_flags & 17))
		put_space(&(*value), &(*amt));
	put_sign(&(*value), &(*amt));
	put_prefix(&(*value), &(*amt));
	put_zero(&(*value), &(*amt));
	if ((g_flags & 48) == 48 && !(g_flags & 1))
		put_space(&(*value), &(*amt));
	put_abs(&(*value), &(*amt));
	put_uabs(&(*value), &(*amt));
	put_str(*value, &(*amt));
	if ((g_flags & 33) == 33)
		put_space(&(*value), &(*amt));
	*str += 1;
	return (1);
}

char	exe_wsymb(void **value, const char **str, int *amt)
{
	extern int	g_flags;
	
	if (!(g_flags & 32))
		return (0);
	len_arg(&(*value));
	if (!(g_flags & 1))
		put_space(&(*value), &(*amt));
	if (g_flags & 262144)
		put_char((char)(*value), &(*str), &(*amt));
	else
		put_char(**str, &(*str), &(*amt));
	if (g_flags & 1)
		put_space(&(*value), &(*amt));
	return (1);
}

void	exe_other(void **value, const char **str, int *amt)
{
	extern int	g_flags;
	
	if (exe_numstr(&(*value), &(*str), &(*amt)))
		return ;
	if (exe_wsymb(&(*value), &(*str), &(*amt)))
		return ;
	if (g_flags & 262144)
	{
		put_char((char)(*value), &(*str), &(*amt));
		return ;
	}
	if (**str != '\0')
		put_char(**str, &(*str), &(*amt));
}

void	intrp(va_list *args, long double *value_f, void **value)
{
	extern int	g_flags;
	
	if ((g_flags & 1050624) == 1050624)
	{
		*value_f = va_arg(*args, long double);
		return ;
	}
	if (g_flags & 1048576)
	{
		*value_f = va_arg(*args, double);
		return ;
	}
	*value = va_arg(*args, void *);
}

int		ft_printf(const char *str, ...)
{
	int				amt;
	va_list			args;
	// int				flags;
	void			*value;
	long double		value_f;

	amt = 0;
	va_start(args, str);
	while (*str)
	{
		if (!put_freesmb(&str, &amt))
			break ;
		if (check_lastfreesmb(&str, &amt))
			continue ;
		if (!parsing(&str, &args))
			break ;
		if (*str != '%')
			intrp(&args, &value_f, &value);
		if (exe_float(&value_f, &str, &amt))
			continue ;
		exe_other(&value, &str, &amt);
	}
	va_end(args);
	return (amt);
}

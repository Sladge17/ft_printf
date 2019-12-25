/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/25 18:05:07 by jthuy            ###   ########.fr       */
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

void	exe_other(void **value, int *flags, const char **str, int *amt)
{
	if (exe_numstr(&(*value), &(*flags), &(*str), &(*amt)))
		return ;
	if (exe_wsymb(&(*value), &(*flags), &(*str), &(*amt)))
		return ;
	if (*flags & 262144)
	{
		put_char((char)(*value), &(*str), &(*amt));
		return ;
	}
	if (**str != '\0')
		put_char(**str, &(*str), &(*amt));
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
	int				amt;
	va_list			args;
	int				flags;
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
		if (!parsing(&flags, &str))
			break ;
		if (*str != '%')
			intrp(&args, &value_f, &value, &flags);
		if (exe_float(&value_f, &flags, &str, &amt))
			continue ;
		exe_other(&value, &flags, &str, &amt);
	}
	va_end(args);
	return (amt);
}

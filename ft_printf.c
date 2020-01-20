/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:14 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/20 18:17:11 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int				amt;
	va_list			args;
	void			*value;
	long double		value_f;

	amt = 0;
	va_start(args, str);
	while (*str)
	{
		if (!put_freesmb(&str, &amt))
			break ;
		if (put_lastfreesmb(&str, &amt))
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
	if (((g_flags & 112) == 112 && !(g_flags & 15)
		&& !(g_flags & 1048576) && g_accuracy >= 0)
		|| (g_flags & 233472 && (g_flags & 80) == 80 && g_accuracy >= 0))
		g_flags ^= 16;
	if (g_accuracy < 0)
		g_accuracy = g_flags & 16384 ? -g_accuracy : 0;
	return (1);
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

void	def_lenarg(void **value)
{
	extern int	g_flags;
	extern int	g_accuracy;
	extern int	g_lenarg;

	g_lenarg = 1;
	if (g_flags & 16384 && !(*value))
	{
		g_lenarg = 6;
		return ;
	}
	if ((g_flags & 32864) == 32864 && !(g_flags & 8) && !g_accuracy)
		g_lenarg = 0;
	if (!(*value))
		return ;
	if (g_flags & 4096)
		g_lenarg = len_numb(&(*value));
	if (g_flags & 8192)
		g_lenarg = len_unumb((long int)(*value));
	if (g_flags & 245760 || g_flags & 524288)
		g_lenarg = len_str((char *)(*value));
}

void	def_color(const char **str)
{
	if (*(*str + 1) == '/' && *(*str + 2) == '}')
	{
		write(1, "\e[0m", 4);
		*str += 3;
		return ;
	}
	if (black(&(*str)))
		return ;
	if (red(&(*str)))
		return ;
	if (green(&(*str)))
		return ;
	if (yellow(&(*str)))
		return ;
	if (blue(&(*str)))
		return ;
	if (magenta(&(*str)))
		return ;
	if (cyan(&(*str)))
		return ;
	if (white(&(*str)))
		return ;
}

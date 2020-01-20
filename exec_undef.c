/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_undef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:12:07 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/20 12:37:18 by jthuy            ###   ########.fr       */
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

char	def_fasttype(const char **str)
{
	extern int	g_flags;

	if (**str == 'U')
	{
		g_flags |= 9216;
		return (1);
	}
	if (**str == 'h' && *(*str + 1) == 'U')
	{
		g_flags |= 9216;
		*str += 1;
		return (1);
	}
	return (0);
}

void	def_modifier(const char **str)
{
	extern int	g_flags;

	if (**str == 'h' && *(*str + 1) == 'h' && *(*str + 2) == 'l')
	{
		g_flags |= 1024;
		*str += 3;
	}
	if (**str == 'h')
		find_modsymb(&(*str), 256);
	if (**str == 'l' || **str == 'z')
		find_modsymb(&(*str), 1024);
	if (**str == 'j')
	{
		g_flags |= 1024;
		*str += 1;
		if (**str == 'z' || **str == 'h')
			*str += 1;
	}
	if (**str == 'L')
	{
		g_flags |= 2048;
		*str += 1;
	}
}

void	find_modsymb(const char **str, short flag)
{
	extern int	g_flags;

	if (*(*str + 1) == **str || *(*str + 1) == 'h' || *(*str + 1) == 'j')
	{
		g_flags |= flag;
		*str += 2;
		if (**str == 'l')
			*str += 1;
		if (**str == 'z')
			*str += 1;
		if (**str == 'h')
			*str += 1;
		return ;
	}
	g_flags |= flag >> 1;
	*str += 1;
}

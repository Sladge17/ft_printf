/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:15:04 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/17 13:10:02 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	find_minus(const char **str)
{
	extern int	g_flags;

	if (**str == '-')
	{
		g_flags |= 1;
		*str += 1;
		return (1);
	}
	return (0);
}

char	find_plus(const char **str)
{
	extern int	g_flags;

	if (**str == '+')
	{
		g_flags |= 2;
		*str += 1;
		return (1);
	}
	return (0);
}

char	find_space(const char **str)
{
	extern int	g_flags;

	if (**str == ' ')
	{
		g_flags |= 4;
		*str += 1;
		return (1);
	}
	return (0);
}

char	find_lattice(const char **str)
{
	extern int	g_flags;

	if (**str == '#')
	{
		g_flags |= 8;
		*str += 1;
		return (1);
	}
	return (0);
}

char	find_zero(const char **str)
{
	extern int	g_flags;

	if (**str == '0')
	{
		g_flags |= 16;
		*str += 1;
		return (1);
	}
	return (0);
}

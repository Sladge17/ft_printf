/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:41:25 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/20 18:21:28 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	black(const char **str)
{
	if (*(*str + 1) == 'b'
	&& *(*str + 2) == 'l'
	&& *(*str + 3) == 'a'
	&& *(*str + 4) == 'c'
	&& *(*str + 5) == 'k'
	&& *(*str + 6) == '}')
	{
		write(1, "\e[30m", 5);
		*str += 7;
		return (1);
	}
	return (0);
}

char	red(const char **str)
{
	if (*(*str + 1) == 'r'
	&& *(*str + 2) == 'e'
	&& *(*str + 3) == 'd'
	&& *(*str + 4) == '}')
	{
		write(1, "\e[31m", 5);
		*str += 5;
		return (1);
	}
	return (0);
}

char	green(const char **str)
{
	if (*(*str + 1) == 'g'
	&& *(*str + 2) == 'r'
	&& *(*str + 3) == 'e'
	&& *(*str + 4) == 'e'
	&& *(*str + 5) == 'n'
	&& *(*str + 6) == '}')
	{
		write(1, "\e[32m", 5);
		*str += 7;
		return (1);
	}
	return (0);
}

char	yellow(const char **str)
{
	if (*(*str + 1) == 'y'
	&& *(*str + 2) == 'e'
	&& *(*str + 3) == 'l'
	&& *(*str + 4) == 'l'
	&& *(*str + 5) == 'o'
	&& *(*str + 6) == 'w'
	&& *(*str + 7) == '}')
	{
		write(1, "\e[33m", 5);
		*str += 8;
		return (1);
	}
	return (0);
}

char	blue(const char **str)
{
	if (*(*str + 1) == 'b'
	&& *(*str + 2) == 'l'
	&& *(*str + 3) == 'u'
	&& *(*str + 4) == 'e'
	&& *(*str + 5) == '}')
	{
		write(1, "\e[34m", 5);
		*str += 6;
		return (1);
	}
	return (0);
}

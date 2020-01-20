/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:05:43 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/20 18:21:37 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	magenta(const char **str)
{
	if (*(*str + 1) == 'm'
	&& *(*str + 2) == 'a'
	&& *(*str + 3) == 'g'
	&& *(*str + 4) == 'e'
	&& *(*str + 5) == 'n'
	&& *(*str + 6) == 't'
	&& *(*str + 7) == 'a'
	&& *(*str + 8) == '}')
	{
		write(1, "\e[35m", 5);
		*str += 9;
		return (1);
	}
	return (0);
}

char	cyan(const char **str)
{
	if (*(*str + 1) == 'c'
	&& *(*str + 2) == 'y'
	&& *(*str + 3) == 'a'
	&& *(*str + 4) == 'n'
	&& *(*str + 5) == '}')
	{
		write(1, "\e[36m", 5);
		*str += 6;
		return (1);
	}
	return (0);
}

char	white(const char **str)
{
	if (*(*str + 1) == 'w'
	&& *(*str + 2) == 'h'
	&& *(*str + 3) == 'i'
	&& *(*str + 4) == 't'
	&& *(*str + 5) == 'e'
	&& *(*str + 6) == '}')
	{
		write(1, "\e[37m", 5);
		*str += 7;
		return (1);
	}
	return (0);
}

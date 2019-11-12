/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_lengths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:12:48 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/12 21:39:48 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		def_width(const char **str)
{
	int		width;

	width = 0;
	while ('0' <= **str && **str <= '9')
	{
		width = width * 10 + (**str - '0');
		*str += 1;
	}
	return (width);
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

int		len_sign(int value_d, char flags)
{
	if (value_d < 0)
		return (1);
	if (flags & 2 || flags & 4)
		return (1);
	return (0);
}

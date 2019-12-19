/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_lengths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:12:48 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/17 18:15:02 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_numb(void **value, unsigned int *flags)
{
	if (*flags & 128 && (short)(*value) < 0)
		return (len_unumb(-(short)(*value)));
	if (*flags & 256 && (char)(*value) < 0)
		return (len_unumb(-(char)(*value)));
	if (*flags & 1536 && (long int)(*value) < 0)
		return (len_unumb(-(long int)(*value)));
	if (!(*flags & 3968) && (int)(*value) < 0)
		return (len_unumb(-(int)(*value)));
	return (len_unumb((long int)(*value)));
}

int		len_unumb(unsigned long int value)
{
	int		len;

	len = 1;
	while (value > 9)
	{
		value /= 10;
		len += 1;
	}
	return (len);
}

char	len_sign(void **value, unsigned int *flags)
{
	if (!(*flags & 4096))
		return (0);
	if ((*flags & 4096) && ((*flags & 128 && (short)(*value) < 0)
		|| (*flags & 6)
		|| (*flags & 256 && (char)(*value) < 0)
		|| (*flags & 1536 && (long int)(*value) < 0)
		|| (!(*flags & 3968) && (int)(*value) < 0)))
		return (1);
	return (0);
}

int		len_str(const char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len += 1;
	return (len);
}

void	len_arg(void **value, unsigned int *flags)
{
	extern int	g_accuracy;
	extern int	g_lenarg;

	g_lenarg = 1;
	if (*flags & 16384 && !(*value))
	{
		g_lenarg = 6;
		return ;
	}
	if ((*flags & 32864) == 32864 && !(*flags & 8) &&!g_accuracy)
		g_lenarg = 0;
	if (!(*value))
		return ;
	if (*flags & 4096)
		g_lenarg = len_numb(&(*value), &(*flags));
	if (*flags & 8192)
		g_lenarg = len_unumb((long int)(*value));
	if (*flags & 245760 || *flags & 524288)
		g_lenarg = len_str((char *)(*value));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_lengths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:12:48 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/16 17:28:55 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_numb(void **value)
{
	extern int	g_flags;
	
	if (g_flags & 128 && (short)(*value) < 0)
		return (len_unumb(-(short)(*value)));
	if (g_flags & 256 && (char)(*value) < 0)
		return (len_unumb(-(char)(*value)));
	if (g_flags & 1536 && (long int)(*value) < 0)
		return (len_unumb(-(long int)(*value)));
	if (!(g_flags & 3968) && (int)(*value) < 0)
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

char	len_sign(void **value)
{
	extern int	g_flags;
	
	if (!(g_flags & 4096))
		return (0);
	if ((g_flags & 4096) && ((g_flags & 128 && (short)(*value) < 0)
		|| (g_flags & 6)
		|| (g_flags & 256 && (char)(*value) < 0)
		|| (g_flags & 1536 && (long int)(*value) < 0)
		|| (!(g_flags & 3968) && (int)(*value) < 0)))
		return (1);
	return (0);
}

char	len_sign_f(long double *value_f)
{
	extern int	g_flags;
	
	if (*value_f < 0 || g_flags & 6)
		return (1);
	return (0);
	
	// if (!(*flags & 4096))
	// 	return (0);
	// if ((*flags & 4096) && ((*flags & 128 && (short)(*value) < 0)
	// 	|| (*flags & 6)
	// 	|| (*flags & 256 && (char)(*value) < 0)
	// 	|| (*flags & 1536 && (long int)(*value) < 0)
	// 	|| (!(*flags & 3968) && (int)(*value) < 0)))
	// 	return (1);
	// return (0);
}

int		len_str(const char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len += 1;
	return (len);
}

void	len_arg(void **value)
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
	if ((g_flags & 32864) == 32864 && !(g_flags & 8) &&!g_accuracy)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:53:25 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/20 13:15:37 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	exe_float(long double *value_f, const char **str, int *amt)
{
	long int	unit;
	char		*remainder;
	extern int	g_flags;
	extern int	g_accuracy;

	if (!(g_flags & 1048576))
		return (0);
	if (!(g_flags & 64))
		g_accuracy = 6;
	if (g_flags & 32 && !(g_flags & 1) && !(g_flags & 16))
		put_space_f(&(*value_f), &(*amt));
	put_sign_f(&(*value_f), &(*amt));
	if ((g_flags & 48) == 48 && !(g_flags & 1))
		put_space_f(&(*value_f), &(*amt));
	unit = *value_f < 0 ? -(long int)(*value_f) : (long int)(*value_f);
	remainder = (char *)malloc(sizeof(char) * 21);
	if (!remainder)
		exit(0);
	def_remainder(&remainder, *value_f, unit);
	fixput_float(&unit, &remainder, &(*amt));
	free(remainder);
	if ((g_flags & 33) == 33)
		put_space_f(&(*value_f), &(*amt));
	*str += 1;
	return (1);
}

void	fixput_float(long int *unit, char **remainder, int *amt)
{
	fix_float(&(*unit), &(*remainder));
	put_float(&(*unit), &(*remainder), &(*amt));
}

void	exe_other(void **value, const char **str, int *amt)
{
	extern int	g_flags;

	if (exe_numstr(&(*value), &(*str), &(*amt)))
		return ;
	if (exe_char(&(*value), &(*str), &(*amt)))
		return ;
	if (g_flags & 262144)
	{
		put_char((char)(*value), &(*str), &(*amt));
		return ;
	}
	if (**str != '\0')
		put_char(**str, &(*str), &(*amt));
}

char	exe_numstr(void **value, const char **str, int *amt)
{
	extern int	g_flags;

	if (!(g_flags & 782336))
		return (0);
	conversion(&(*value));
	def_lenarg(&(*value));
	if (g_flags & 32 && !(g_flags & 17))
		put_space(&(*value), &(*amt));
	put_sign(&(*value), &(*amt));
	put_prefix(&(*value), &(*amt));
	put_zero(&(*value), &(*amt));
	if ((g_flags & 48) == 48 && !(g_flags & 1))
		put_space(&(*value), &(*amt));
	put_abs(&(*value), &(*amt));
	put_uabs(&(*value), &(*amt), &g_flags);
	put_str(*value, &(*amt));
	if ((g_flags & 33) == 33)
		put_space(&(*value), &(*amt));
	*str += 1;
	return (1);
}

char	exe_char(void **value, const char **str, int *amt)
{
	extern int	g_flags;

	if (!(g_flags & 32))
		return (0);
	def_lenarg(&(*value));
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

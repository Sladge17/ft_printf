/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:59:11 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/21 17:25:02 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_oct(void **value, unsigned long *bitend, char **oct)
{
	int					len;
	int					factor;
	int					i;
	unsigned long int	typeborder;

	shift_typeborder(&typeborder);
	len = 0;
	while (*bitend)
	{
		factor = 0;
		i = 2;
		while (i > -1)
		{
			if ((long int)(*value) & *bitend && *bitend <= typeborder)
				factor += 1 << i;
			*bitend >>= 1;
			i -= 1;
		}
		(*oct)[len] = factor + 48;
		len += 1;
	}
}

void	shift_typeborder(unsigned long int *typeborder)
{
	extern int	g_flags;

	if (g_flags & 128)
		*typeborder = 1UL << 15;
	if (g_flags & 256)
		*typeborder = 1UL << 7;
	if (g_flags & 1536)
		*typeborder = 1UL << 63;
	if (!(g_flags & 1920))
		*typeborder = 1UL << 31;
}

void	conv_hex(void **value, unsigned long *bitend, char **hex, char index)
{
	extern int	g_flags;
	int			len;
	int			zeroflag;
	int			factor;

	len = 0;
	zeroflag = 0;
	while (*bitend)
	{
		def_factor(&factor, value, bitend);
		if (!zeroflag && g_flags & 524288 && !factor)
		{
			(*hex)[12 - len] = '\0';
			len += 1;
			continue ;
		}
		if (!zeroflag)
		{
			zeroflag = 1;
			len = 0;
		}
		(*hex)[len] = factor < 10 ? factor + 48 : factor + index - 33;
		len += 1;
	}
}

void	def_factor(int *factor, void **value, unsigned long *bitend)
{
	int		i;

	*factor = 0;
	i = 3;
	while (i > -1)
	{
		if ((long int)(*value) & *bitend)
			*factor += 1 << i;
		*bitend >>= 1;
		i -= 1;
	}
}

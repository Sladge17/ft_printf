/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_bitend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:28:32 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/21 17:26:34 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	def_bitend(unsigned long int *bitend, void **value)
{
	extern int	g_flags;
	char		index;

	index = g_flags & 32768 ? 3 : 4;
	if (g_flags & 128)
	{
		def_bitend_short(bitend, (short)(*value), index);
		return ;
	}
	if (g_flags & 256)
	{
		def_bitend_char(bitend, (char)(*value), index);
		return ;
	}
	if (g_flags & 1536)
	{
		def_bitend_lint(bitend, (long int)(*value), index);
		return ;
	}
	def_bitend_int(bitend, (int)(*value), index);
}

void	def_bitend_int(unsigned long int *bitend, int value, char bitcnt)
{
	int		bitshift;
	int		bitmask;
	int		i;

	bitmask = 1;
	i = 0;
	while (i < 32)
	{
		if (value & bitmask)
			bitshift = i;
		i += 1;
		bitmask <<= 1;
	}
	while ((bitshift + 1) % bitcnt)
		bitshift += 1;
	*bitend = 1;
	*bitend <<= bitshift;
}

void	def_bitend_short(unsigned long int *bitend, short value, char bitcnt)
{
	int			bitshift;
	short		bitmask;
	int			i;

	bitmask = 1;
	i = 0;
	while (i < 16)
	{
		if (value & bitmask)
			bitshift = i;
		i += 1;
		bitmask <<= 1;
	}
	while ((bitshift + 1) % bitcnt)
		bitshift += 1;
	*bitend = 1;
	*bitend <<= bitshift;
}

void	def_bitend_char(unsigned long int *bitend, char value, char bitcnt)
{
	int			bitshift;
	char		bitmask;
	int			i;

	bitmask = 1;
	i = 0;
	while (i < 8)
	{
		if (value & bitmask)
			bitshift = i;
		i += 1;
		bitmask <<= 1;
	}
	while ((bitshift + 1) % bitcnt)
		bitshift += 1;
	*bitend = 1;
	*bitend <<= bitshift;
}

void	def_bitend_lint(unsigned long int *bitend, long int value, char bitcnt)
{
	int			bitshift;
	long int	bitmask;
	int			i;

	bitmask = 1;
	i = 0;
	while (i < 64)
	{
		if (value & bitmask)
			bitshift = i;
		i += 1;
		bitmask <<= 1;
	}
	while ((bitshift + 1) % bitcnt)
		bitshift += 1;
	*bitend = 1;
	*bitend <<= bitshift;
}

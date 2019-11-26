/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:43:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/26 15:47:35 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		binto_oct(int value)
{
	int		oct;
	int		bitmask;
	int		i;
	int		factor;

	bitmask = 1;
	bitmask <<= def_bitborder(value, 3);
	oct = 0;
	while (bitmask)
	{
		factor = 0;
		i = 0;
		while (i < 3)
		{
			if (value & bitmask)
				factor += two_inpower(2 - i);
			bitmask >>= 1;
			i += 1;
		}
		oct = oct * 10 + factor;
	}
	return (oct);
}

char	*binto_hex(int value, char index)
{
	char	*hex;
	unsigned int	bitmask;
	int		i;
	int		factor;
	int		len;

	bitmask = 1;
	bitmask <<= def_bitborder(value, 4);
	len = 0;
	while (bitmask)
	{
		len += 1;
		bitmask >>= 4;
	}
	hex = (char *)malloc(sizeof(char) * (len + 1));
	hex[len] = '\0';
	bitmask = 1;
	bitmask <<= ((4 * len) - 1);
	len = 0;
	while (bitmask)
	{
		factor = 0;
		i = 0;
		while (i < 4)
		{
			if (value & bitmask)
				factor += two_inpower(3 - i);
			bitmask >>= 1;
			i += 1;
		}
		if (factor < 10)
		{
			hex[len] = factor + 48;
			len += 1;
			continue ;
		}
		hex[len] = factor + index - 33;
		len += 1;
	}
	return (hex);
}

int		def_bitborder(int value, char bit_count)
{
	int		bitborder;
	int		bitmask;
	int		i;

	bitmask = 1;
	i = 0;
	while (i < 32)
	{
		if (value & bitmask)
			bitborder = i;
		i += 1;
		bitmask <<= 1;
	}
	while ((bitborder + 1) % bit_count)
		bitborder += 1;
	return (bitborder);
}

int		two_inpower(int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (2);
	return (two_inpower(power - 1) * 2);
}

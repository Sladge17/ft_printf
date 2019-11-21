/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:43:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/21 14:02:49 by jthuy            ###   ########.fr       */
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
	bitmask <<= def_bitborder(value);
	oct = 0;
	while (bitmask)
	{
		factor = 0;
		i = 0;
		while (i < 3)  // <-- need change for hex
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

int		def_bitborder(int value)
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
	while ((bitborder + 1) % 3)  // <-- need change for hex
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

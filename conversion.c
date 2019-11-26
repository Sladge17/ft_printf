/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:43:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/26 17:29:01 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		binto_oct(int value)
{
	int				oct;
	unsigned int	bitborder;
	int				i;
	int				factor;

	def_bitborder(&bitborder, value, 3);
	oct = 0;
	while (bitborder)
	{
		factor = 0;
		i = 0;
		while (i < 3)
		{
			if (value & bitborder)
				factor += two_inpower(2 - i);
			bitborder >>= 1;
			i += 1;
		}
		oct = oct * 10 + factor;
	}
	return (oct);
}

// char	*binto_hex(int value, char index)
// {
// 	char			*hex;
// 	unsigned int	bitborder;
// 	int				i;
// 	int				factor;
// 	int				len;

// 	def_bitborder(&bitborder, value, 4);
// 	len = 0;
// 	while (bitborder)
// 	{
// 		len += 1;
// 		bitborder >>= 4;
// 	}
// 	hex = (char *)malloc(sizeof(char) * (len + 1));
// 	hex[len] = '\0';
// 	bitborder = 1;
// 	bitborder <<= ((4 * len) - 1);
// 	len = 0;
// 	while (bitborder)
// 	{
// 		factor = 0;
// 		i = 0;
// 		while (i < 4)
// 		{
// 			if (value & bitborder)
// 				factor += two_inpower(3 - i);
// 			bitborder >>= 1;
// 			i += 1;
// 		}
// 		if (factor < 10)
// 		{
// 			hex[len] = factor + 48;
// 			len += 1;
// 			continue ;
// 		}
// 		hex[len] = factor + index - 33;
// 		len += 1;
// 	}
// 	return (hex);
// }

void	binto_hex(void **value, char index)
{
	char			*hex;
	unsigned int	bitborder;
	int				i;
	int				factor;
	int				len;

	def_bitborder(&bitborder, (int)(*value), 4);
	len = 0;
	while (bitborder)
	{
		len += 1;
		bitborder >>= 4;
	}
	hex = (char *)malloc(sizeof(char) * (len + 1));
	hex[len] = '\0';
	bitborder = 1;
	bitborder <<= ((4 * len) - 1);
	len = 0;
	while (bitborder)
	{
		factor = 0;
		i = 0;
		while (i < 4)
		{
			if ((int)(*value) & bitborder)
				factor += two_inpower(3 - i);
			bitborder >>= 1;
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
	*value = hex;
	free(hex);
}

void	def_bitborder(unsigned int *bitborder, int value, char bit_count)
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
	while ((bitshift + 1) % bit_count)
		bitshift += 1;
	*bitborder = 1;
	*bitborder <<= bitshift;
}

int		two_inpower(int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (2);
	return (two_inpower(power - 1) * 2);
}

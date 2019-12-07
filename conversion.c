/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:43:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/07 17:29:23 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion(unsigned int *flags, void **value)
{
	if (!(*flags & 229376))
		return;
	if (*flags & 229376 && !(long int)(*value))
	{
		*value = 0;
		return ;
	}
	if (*flags & 32768)
	{
		binto_oct(&(*value), &(*flags));
		return ;
	}
	if (*flags & 65536)
	{
		binto_hex(&(*value), &(*flags), 'x');
		return ;
	}
	if (*flags & 131072)
	{
		binto_hex(&(*value), &(*flags), 'X');
		return ;
	}
}

void	binto_oct(void **value, unsigned int *flags)
{
	char				*oct;
	unsigned long int	bitborder;
	int					i;
	int					factor;
	int					len;

	if ((int)(*value) == 2147483647)
	{
		*value = "17777777777";
		return ;
	}
	if ((int)(*value) == -2147483648)
	{
		*value = "20000000000";
		return ;
	}
	def_bitborder(&bitborder, &(*value), &(*flags));
	len = 0;
	while (bitborder)
	{
		len += 1;
		bitborder >>= 3;
	}
	oct = (char *)malloc(sizeof(char) * (len + 1));
	if (!oct)
	{
		*value = NULL;
		return ;
	}
	oct[len] = '\0';
	bitborder = 1;
	bitborder <<= ((3 * len) - 1);
	len = 0;
	while (bitborder)
	{
		factor = 0;
		i = 2;
		while (i > -1)
		{
			if ((long int)(*value) & bitborder)
				factor += 1 << i;
			bitborder >>= 1;
			i -= 1;
		}
		oct[len] = factor + 48;
		len += 1;
	}
	*value = oct;
	free(oct);
}

void	binto_hex(void **value, unsigned int *flags, char index)
{
	char				*hex;
	unsigned long int	bitborder;
	int					i;
	int					factor;
	int					len;

	def_bitborder(&bitborder, &(*value), &(*flags));
	len = 0;
	while (bitborder)
	{
		len += 1;
		bitborder >>= 4;
	}
	hex = (char *)malloc(sizeof(char) * (len + 1));
	if (!hex)
	{
		*value = NULL;
		return ;
	}
	hex[len] = '\0';
	bitborder = 1;
	bitborder <<= ((4 * len) - 1);
	len = 0;
	while (bitborder)
	{
		factor = 0;
		i = 3;
		while (i > -1)
		{
			if ((long int)(*value) & bitborder)
				factor += 1 << i;
			bitborder >>= 1;
			i -= 1;
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


void	def_bitborder(long int *bitborder, void **value, unsigned int *flags)
{
	char	index;
	
	index = *flags & 32768 ? 3 : 4;
	if (*flags & 1536)
	{
		def_bitborder_lint(&(*bitborder), (long int)(*value), index);
		return ;
	}
	def_bitborder_int(&(*bitborder), (int)(*value), index);
}

void	def_bitborder_int(long int *bitborder, int value, char bit_count)
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

void	def_bitborder_lint(long int *bitborder, long int value, char bit_count)
{
	int						bitshift;
	unsigned long long int	bitmask;
	int						i;

	bitmask = 1;
	i = 0;
	while (i < 64)
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

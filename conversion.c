/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:43:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/24 20:05:19 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion(void **value, int *flags)
{
	if (!(*flags & 753664))
		return;
	if (*flags & 753664 && !(long int)(*value))
	{
		*value = 0;
		return ;
	}
	if (*flags & 32768)
	{
		binto_oct(&(*value), &(*flags));
		return ;
	}
	if (*flags & 589824)
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

void	binto_oct(void **value, int *flags)
{
	char				*oct;
	unsigned long int	bitborder;
	int					i;
	int					factor;
	int					len;
	unsigned long int	typeborder;

	if ((unsigned long)(*value) == ~0UL)
	{
		*value = "1777777777777777777777";
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
	if (*flags & 128)
		typeborder = 1UL << 15;
	if (*flags & 256)
		typeborder = 1UL << 7;
	if (*flags & 1536)
		typeborder = 1UL << 63;
	if (!(*flags & 1920))
		typeborder = 1UL << 31;
	len = 0;
	while (bitborder)
	{
		factor = 0;
		i = 2;
		while (i > -1)
		{
			if ((long int)(*value) & bitborder && bitborder <= typeborder)
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

void	binto_hex(void **value, int *flags, char index)
{
	char				*hex;
	unsigned long int	bitborder;
	int					i;
	int					factor;
	int					len;
	char				zeroflag;

	zeroflag = 0;
	len = 12;
	if (!(*flags & 524288))
	{
		def_bitborder(&bitborder, &(*value), &(*flags));
		len = 0;
		while (bitborder)
		{
			len += 1;
			bitborder >>= 4;
		}
	}

	
	// def_bitborder(&bitborder, &(*value), &(*flags));
	// len = 0;
	// while (bitborder)
	// {
	// 	len += 1;
	// 	bitborder >>= 4;
	// }	
	
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

		if (!zeroflag && *flags & 524288 && !factor)
		{
			hex[12 - len] = '\0';
			len += 1;
			continue ;
		}
		if (!zeroflag)
		{
			zeroflag = 1;
			len = 0;
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


void	def_bitborder(unsigned long int *bitborder, void **value, int *flags)
{
	char	index;
	
	index = *flags & 32768 ? 3 : 4;
	if (*flags & 128)
	{
		def_bitborder_short(&(*bitborder), (short)(*value), index);
		return ;
	}
	if (*flags & 256)
	{
		def_bitborder_char(&(*bitborder), (char)(*value), index);
		return ;
	}
	if (*flags & 1536)
	{
		def_bitborder_lint(&(*bitborder), (long int)(*value), index);
		return ;
	}
	def_bitborder_int(&(*bitborder), (int)(*value), index);
}

void	def_bitborder_int(unsigned long int *bitborder, int value, char bit_count)
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

void	def_bitborder_short(unsigned long int *bitborder, short value, char bit_count)
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
	while ((bitshift + 1) % bit_count)
		bitshift += 1;
	*bitborder = 1;
	*bitborder <<= bitshift;
}

void	def_bitborder_char(unsigned long int *bitborder, char value, char bit_count)
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
	while ((bitshift + 1) % bit_count)
		bitshift += 1;
	*bitborder = 1;
	*bitborder <<= bitshift;
}

void	def_bitborder_lint(unsigned long int *bitborder, long int value, char bit_count)
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
	while ((bitshift + 1) % bit_count)
		bitshift += 1;
	*bitborder = 1;
	*bitborder <<= bitshift;
}

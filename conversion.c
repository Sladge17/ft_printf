/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:43:02 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/17 19:13:28 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion(void **value)
{
	extern int	g_flags;

	if (!(g_flags & 753664))
		return ;
	if (g_flags & 753664 && !(long int)(*value))
	{
		*value = 0;
		return ;
	}
	if (g_flags & 32768)
	{
		binto_oct(&(*value));
		return ;
	}
	if (g_flags & 589824)
	{
		binto_hex(&(*value), 'x');
		return ;
	}
	if (g_flags & 131072)
	{
		binto_hex(&(*value), 'X');
		return ;
	}
}

void	binto_oct(void **value)
{
	char				*oct;
	unsigned long int	bitend;
	int					len;

	if ((unsigned long)(*value) == ~0UL)
	{
		*value = "1777777777777777777777";
		return ;
	}
	def_bitend(&bitend, &(*value));
	def_lenb(&len, &bitend, 3);
	if (new_str(&oct, &len))
	{
		*value = NULL;
		return ;
	}
	bitend = 1;
	bitend <<= ((3 * len) - 1);
	conv_oct(&(*value), &bitend, &oct);
	*value = oct;
	free(oct);
}

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

void	def_lenb(int *len, unsigned long int *bitend, int count)
{
	*len = 0;
	while (*bitend)
	{
		*len += 1;
		*bitend >>= count;
	}
}

char	new_str(char **numb, int *len)
{
	*numb = (char *)malloc(sizeof(char) * (*len + 1));
	if (!(*numb))
		return (1);
	(*numb)[*len] = '\0';
	return (0);
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

void	binto_hex(void **value, char index)
{
	extern int			g_flags;
	char				*hex;
	unsigned long int	bitend;
	int					len;

	len = 12;
	if (!(g_flags & 524288))
	{
		def_bitend(&bitend, &(*value));
		def_lenb(&len, &bitend, 4);
	}
	if (new_str(&hex, &len))
	{
		*value = NULL;
		return ;
	}
	bitend = 1;
	bitend <<= ((4 * len) - 1);
	conv_hex(&(*value), &bitend, &hex, index);
	*value = hex;
	free(hex);
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
		def_factor(&factor, &(*value), &(*bitend));
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

void	def_bitend(unsigned long int *bitend, void **value)
{
	extern int	g_flags;
	char		index;

	index = g_flags & 32768 ? 3 : 4;
	if (g_flags & 128)
	{
		def_bitend_short(&(*bitend), (short)(*value), index);
		return ;
	}
	if (g_flags & 256)
	{
		def_bitend_char(&(*bitend), (char)(*value), index);
		return ;
	}
	if (g_flags & 1536)
	{
		def_bitend_lint(&(*bitend), (long int)(*value), index);
		return ;
	}
	def_bitend_int(&(*bitend), (int)(*value), index);
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

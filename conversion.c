/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:43:02 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/21 17:25:52 by jthuy            ###   ########.fr       */
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
		binto_oct(value);
		return ;
	}
	if (g_flags & 589824)
	{
		binto_hex(value, 'x');
		return ;
	}
	if (g_flags & 131072)
	{
		binto_hex(value, 'X');
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
	def_bitend(&bitend, value);
	def_lenb(&len, &bitend, 3);
	if (new_str(&oct, &len))
	{
		*value = NULL;
		return ;
	}
	bitend = 1;
	bitend <<= ((3 * len) - 1);
	conv_oct(value, &bitend, &oct);
	*value = oct;
	free(oct);
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
		def_bitend(&bitend, value);
		def_lenb(&len, &bitend, 4);
	}
	if (new_str(&hex, &len))
	{
		*value = NULL;
		return ;
	}
	bitend = 1;
	bitend <<= ((4 * len) - 1);
	conv_hex(value, &bitend, &hex, index);
	*value = hex;
	free(hex);
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

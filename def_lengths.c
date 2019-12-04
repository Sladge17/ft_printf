/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_lengths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:12:48 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/04 17:19:52 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		len_numb(int value, char len_sign)
int		len_numb(int value)
{
	int		len;

	len = 1;
	value = value < 0 ? (-1) * value : value;
	while (value > 9)
	{
		value /= 10;
		len += 1;
	}
	// return (len + len_sign);
	return (len);
}

int		len_unumb(unsigned int value)
{
	int		len;

	len = 1;
	while (value > 9)
	{
		value /= 10;
		len += 1;
	}
	return (len);
}

char	len_sign(void **value, unsigned int *flags)
// int	len_sign(int value, unsigned int *flags)
{
	// if (flags & 32)
	// 	return (0);
	if (*flags & 8192)
		return (0);
	// if (**str != 's' && !(*flags & 229376) && (int)(*value) < 0)
	if (!(*flags & 16384) && !(*flags & 229376) && (int)(*value) < 0)
	// if (value < 0)
	// if ((int)(*value) & 1 << 31)
		return (1);
	// if (*flags & 2 || *flags & 4)
	if (*flags & 6)
		return (1);
	return (0);
}

int		len_str(const char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len += 1;
	return (len);
}

int		len_symbols(void **value, unsigned int *flags)
{
	int			len_symbols;

	len_symbols = 1;
	if (*flags & 4096)
		len_symbols = len_numb((int)(*value));
	if (*flags & 8192)
		len_symbols = len_unumb((int)(*value));
	if (*flags & 245760)
		len_symbols = len_str((char *)(*value));
	if ((*flags & 32776) == 32776)
		len_symbols += 1;
	if (*flags & 8 && (*flags & 196608))
		len_symbols += 2;
	return (len_symbols);
}

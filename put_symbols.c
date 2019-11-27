/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:06:10 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/27 14:17:58 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char symbol, const char **str, int *amount)
{
	write(1, &symbol, 1);
	if (str)
		*str += 1;
	*amount += 1;
}

char	put_freesmb(const char **str, int *amount)
{
	while (**str != '%')
	{
		if (**str == '\0')
			return (0);
		put_char(**str, &(*str), &(*amount));
	}
	*str += 1;
	return (1);
}

char	check_lastfreesmb(const char **str, int *amount)
{
	int		i;

	if (**str != ' ')
		return (0);
	i = 1;
	if (*(*str + i) == '\0')
		return (0);
	while (*(*str + i) == ' ')
		i += 1;
	if (*(*str + i) == 'h' || *(*str + i) == 'l' || *(*str + i) == 'L')
	{
		*str += i + 1;
		return (0);
	}
	if (*(*str + i) == '-' || *(*str + i) == '+'|| *(*str + i) == '#' 
		|| *(*str + i) == '0' || *(*str + i) == 'c' 
		|| *(*str + i) == 'd' || *(*str + i) == 'i' 
		|| *(*str + i) == 'u' || *(*str + i) == 'o'
		|| *(*str + i) == 'x' || *(*str + i) == 'X')
		return (0);
	*str += i;
	put_char(**str, &(*str), &(*amount));
	return (1);
}

void	put_space(int len_space, short flags, int *amount)
{
	char	space;
	int		i;

	space = ' ';
	if (flags & 16 && !(flags & 1))
		space = '0';
	i = 0;
	while (i < len_space)
	{
		put_char(space, NULL, &(*amount));
		i += 1;
	}
}

void	put_str(char const *string, int *amount)
{
	if (!string)
		return ;
	while (*string != '\0')
	{
		put_char(*string, NULL, &(*amount));
		string += 1;
	}
}

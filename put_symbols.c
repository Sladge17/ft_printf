/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:06:10 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/13 19:00:12 by jthuy            ###   ########.fr       */
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
		|| ('0' <= *(*str + i) && *(*str + i) <= '9') || *(*str + i) == 'c' 
		|| *(*str + i) == 'd' || *(*str + i) == 'i' 
		|| *(*str + i) == 'u' || *(*str + i) == 'o'
		|| *(*str + i) == 'x' || *(*str + i) == 'X')
		return (0);
	*str += i;
	put_char(**str, &(*str), &(*amount));
	return (1);
}

void	put_space(void **value, unsigned int *flags, int *amount)
{
	extern int	g_width;
	extern int	g_accuracy;
	char		space;
	int			len_space;
	int			i;

	int			len_symb;
	char		len_sig;

	if (g_width <= g_accuracy)
		return ;
	
	len_sig = len_sign(&(*value), &(*flags));

		

	len_symb = len_symbols(&(*value), &(*flags));

	

	space = ' ';
	if (*flags & 16 && !(*flags & 1))
		space = '0';

	if ((*flags & 64 && len_symb < g_accuracy) || (*flags & 64 && !g_accuracy && !((int)(*value))))
		len_symb = g_accuracy;
	
	len_space = g_width - len_symb - len_sig;

	// if (*flags & 64 && len_symb < g_accuracy)
	// 	len_space = g_width - g_accuracy;
	
	// NEED FiX
	// if (len_symb < g_accuracy || (*flags & 64 && *flags & 16384))
	// 	len_space = g_width - g_accuracy;
	// else
	// 	len_space = g_width - len_symb - len_sig;

	// if (*flags & 64 && **str == 's')
	// 	len_space = g_width - g_accuracy;
	
	// NEED FiX
	// if (g_accuracy && (*flags & 2 || *flags & 4 || (!(*flags & 16384) && !(*flags & 229376) && (int)(*value) < 0)))
	// 	len_space -= 1;

	// if (*flags & 64 && !g_accuracy && !((int)(*value)))
	// 	len_space = g_width;

	if (!len_symb && *flags & 32 && *flags & 64)
	// if (!len_symb && (*flags & 96) == 96)
		len_space = g_width;

	// if (!(*(int *)value) && *flags & 32 && *flags & 64)
	// 	len_space = g_width;
		
	i = 0;
	while (i < len_space)
	{
		put_char(space, NULL, &(*amount));
		i += 1;
	}
}

void	put_zero(void **value, unsigned int *flags, int *amount)
{
	extern int	g_accuracy;
	int			len_zero;
	int			i;

	int			len_symb;

	if (*flags & 16384)
		return ;
	
	len_symb = len_symbols(&(*value), &(*flags));

	if (!(*flags & 64))
		return ;
	if (g_accuracy == 0 && (int)(*value) == 0)
		return ;
	if (g_accuracy <= len_symb)
		return ;
	len_zero = g_accuracy - len_symb;
	i = 0;
	while (i < len_zero)
	{
		put_char('0', NULL, &(*amount));
		i += 1;
	}
}


void	put_str(char const *string, unsigned int *flags, int *amount)
{
	extern int	g_accuracy;
	int			i;
	
	if (*flags & 12288 || !string)
		return ;
	if (*flags & 64 && !(*flags & 229376) && *string != '\0')
	{
		i = 0;
		while (i < g_accuracy)
		{
			put_char(*string, NULL, &(*amount));
			string += 1;
			i += 1;
		}
		return ;
	}
	while (*string != '\0')
	{
		put_char(*string, NULL, &(*amount));
		string += 1;
	}
}

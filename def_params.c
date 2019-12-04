/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:18:53 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/04 16:33:01 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(unsigned int *flags, const char **str)
{
	while (1)
	{
		if (find_minus(&(*str), &(*flags)))
			continue ;
		if (find_plus(&(*str), &(*flags)))
			continue ;
		if (find_space(&(*str), &(*flags)))
			continue ;
		if (find_lattice(&(*str), &(*flags)))
			continue ;
		if (find_zero(&(*str), &(*flags)))
			continue ;
		break ;
	}
}

void	def_width(unsigned int *flags, const char **str)
{
	extern int	g_width;

	ft_atoi(&g_width, &(*str));
	if (g_width)
		*flags |= 32;
}

void	def_accuracy(unsigned int *flags, const char **str)
{
	extern int	g_accuracy;

	if (**str != '.')
		return ;
	*flags |= 64;
	*str += 1;
	ft_atoi(&g_accuracy, &(*str));
}

void	ft_atoi(int *param, const char **str)
{
	*param = 0;
	while ('0' <= **str && **str <= '9')
	{
		*param = *param * 10 + (**str - '0');
		*str += 1;
	}
}

void	def_modifier(unsigned int *flags, const char **str)
{
	if (**str == 'h')
	{
		find_modsymb(&(*flags), &(*str), 256);
		return ;
	}
	if (**str == 'l')
	{
		find_modsymb(&(*flags), &(*str), 1024);
		return ;
	}
	if (**str == 'L')
	{
		*flags |= 2048;
		*str += 1;
	}
}

void	find_modsymb(unsigned int *flags, const char **str, short code)
{
	if (*(*str + 1) == **str)
	{
		*flags |= code;
		*str += 2;
		return ;
	}
	*flags |= code >> 1;
	*str += 1;
}

void	def_type(unsigned int *flags, const char **str)
{
	if (**str == 'd' || **str == 'i')
		*flags |= 4096;
	if (**str == 'u')
		*flags |= 8192;
	if (**str == 's')
		*flags |= 16384;
	if (**str == 'o')
		*flags |= 32768;
	if (**str == 'x')
		*flags |= 65536;
	if (**str == 'X')
		*flags |= 131072;
	if (**str == 'c')
		*flags |= 262144;
}

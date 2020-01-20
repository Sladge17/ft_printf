/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:18:53 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/20 12:30:08 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(const char **str)
{
	while (1)
	{
		if (find_minus(&(*str)))
			continue ;
		if (find_plus(&(*str)))
			continue ;
		if (find_space(&(*str)))
			continue ;
		if (find_lattice(&(*str)))
			continue ;
		if (find_zero(&(*str)))
			continue ;
		break ;
	}
}

void	def_width(const char **str, va_list *args)
{
	extern int	g_flags;
	extern int	g_width;

	g_width = 0;
	if (**str == '*')
	{
		g_width = va_arg(*args, int);
		if (g_width < 0)
		{
			g_width = -g_width;
			g_flags |= 1;
		}
		*str += 1;
	}
	if ('0' <= **str && **str <= '9')
		ft_atoi(&g_width, &(*str));
	if (g_width)
		g_flags |= 32;
}

void	def_accuracy(const char **str, va_list *args)
{
	extern int	g_flags;
	extern int	g_accuracy;

	if (**str != '.')
		return ;
	g_accuracy = 0;
	g_flags |= 64;
	*str += 1;
	if (**str == '*')
	{
		g_accuracy = va_arg(*args, int);
		*str += 1;
	}
	if ('0' <= **str && **str <= '9')
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

void	def_type(const char **str)
{
	extern int	g_flags;

	if (**str == 'd' || **str == 'i')
		g_flags |= 4096;
	if (**str == 'u')
		g_flags |= 8192;
	if (**str == 's')
		g_flags |= 16384;
	if (**str == 'o')
		g_flags |= 32768;
	if (**str == 'x')
		g_flags |= 65536;
	if (**str == 'X')
		g_flags |= 131072;
	if (**str == 'c')
		g_flags |= 262144;
	if (**str == 'p')
		g_flags |= 524288;
	if (**str == 'f')
		g_flags |= 1048576;
}

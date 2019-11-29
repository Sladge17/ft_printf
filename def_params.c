/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:18:53 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/29 11:36:17 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(short *flags, const char **str)
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

void	def_width(short *flags, const char **str)
{
	extern int	g_width;

	ft_atoi(&g_width, &(*str));
	if (g_width)
		*flags |= 32;
}

void	def_accuracy(short *flags, const char **str)
{
	extern int	g_accuracy;

	if (**str != '.')
		return ;
	*str += 1;
	ft_atoi(&g_accuracy, &(*str));
	// g_accuracy = 0;
	// while ('0' <= **str && **str <= '9')
	// {
	// 	g_accuracy = g_accuracy * 10 + (**str - '0');
	// 	*str += 1;
	// }
	if (g_accuracy)
		*flags |= 64;
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

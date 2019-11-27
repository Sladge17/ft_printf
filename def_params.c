/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:18:53 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/27 19:29:39 by jthuy            ###   ########.fr       */
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
	extern int	width;

	width = 0;
	while ('0' <= **str && **str <= '9')
	{
		width = width * 10 + (**str - '0');
		*str += 1;
	}
	if (width)
		*flags |= 32;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:35:42 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/12 19:24:16 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	check_flag(const char **str)
{
	char	flags;

	flags = 0;
	while (1)
	{
		if (find_minus(&(*str), &flags))
			continue ;
		if (find_plus(&(*str), &flags))
			continue ;
		if (find_space(&(*str), &flags))
			continue ;
		if (find_lattice(&(*str), &flags))
			continue ;
		if (find_zero(&(*str), &flags))
			continue ;
		break ;
	}
	return (flags);
}

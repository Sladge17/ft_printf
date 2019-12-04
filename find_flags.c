/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:15:04 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/04 12:27:00 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	find_minus(const char **str, unsigned int *flags)
{
	if (**str == '-')
	{
		*flags |= 1;
		*str += 1;
		return (1);
	}
	return (0);
}

char	find_plus(const char **str, unsigned int *flags)
{
	if (**str == '+')
	{
		*flags |= 2;
		*str += 1;
		return (1);
	}
	return (0);
}

char	find_space(const char **str, unsigned int *flags)
{
	if (**str == ' ')
	{
		*flags |= 4;
		*str += 1;
		return (1);
	}
	return (0);
}

char	find_lattice(const char **str, unsigned int *flags)
{
	if (**str == '#')
	{
		*flags |= 8;
		*str += 1;
		return (1);
	}
	return (0);
}

char	find_zero(const char **str, unsigned int *flags)
{
	if (**str == '0')
	{
		*flags |= 16;
		*str += 1;
		return (1);
	}
	return (0);
}

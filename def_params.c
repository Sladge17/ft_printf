/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:18:53 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/06 19:23:55 by jthuy            ###   ########.fr       */
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

char	def_fasttype(unsigned int *flags, const char **str)
{
	if (**str == 'U')
	{
		*flags |= 9216;
		return (1);
	}
	if (**str == 'h' && *(*str + 1) == 'U')
	{
		*flags |= 9216;
		*str += 1;
		return (1);
	}
	return (0);
}

void	def_modifier(unsigned int *flags, const char **str)
{
	if (**str == 'h' && *(*str + 1) == 'h' && *(*str + 2) == 'l')
	{
		*flags |= 1024;
		*str += 3;
		return ;
	}
	if (**str == 'h')
	{
		find_modsymb(&(*flags), &(*str), 256);
		return ;
	}
	if (**str == 'l' ||  **str == 'z')
	{
		find_modsymb(&(*flags), &(*str), 1024);
		return ;
	}
	if (**str == 'j')
	{
		*flags |= 1024;
		*str += 1;
		if (**str == 'z' || **str == 'h')
			*str += 1;
		return ;
	}
	if (**str == 'L')
	{
		*flags |= 2048;
		*str += 1;
	}
}

void	find_modsymb(unsigned int *flags, const char **str, short flag)
{
	if (*(*str + 1) == **str || *(*str + 1) == 'h' || *(*str + 1) == 'j')
	{
		*flags |= flag;
		*str += 2;
		if (**str == 'l')
			*str += 1;
		if (**str == 'z')
			*str += 1;
		if (**str == 'h')
			*str += 1;
		return ;
	}
	*flags |= flag >> 1;
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

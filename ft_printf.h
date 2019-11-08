/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:38:44 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/06 19:18:46 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
** find_flags.c
*/
char	find_minus(const char **str, char *flags);
char	find_plus(const char **str, char *flags);
char	find_space(const char **str, char *flags);
char	find_lattice(const char **str, char *flags);
char	find_zero(const char **str, char *flags);

/*
** check_flag.c
*/
char	check_flag(const char **str);



int		def_width(const char **str);

#endif

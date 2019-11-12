/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:38:44 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/12 13:38:22 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
** ft_printf.c
*/


/*
** check_flag.c
*/
char	check_flag(const char **str);

/*
** find_flags.c
*/
char	find_minus(const char **str, char *flags);
char	find_plus(const char **str, char *flags);
char	find_space(const char **str, char *flags);
char	find_lattice(const char **str, char *flags);
char	find_zero(const char **str, char *flags);

/*
** def_lengths.c
*/
int		def_width(const char **str);
int		len_numb_abc(int value_d);
int		len_sign(int value_d, char flags);

/*
** put_symbols.c
*/
int		put_freesmb(const char **str, int *amount);
void	put_abs(int n, int *amount);
void	put_sign(int value_d, char flags, int *amount);
void	put_space(int width, int value_d, char flags, int *amount);
void	ft_putstr(char const *s, int *amount);


#endif

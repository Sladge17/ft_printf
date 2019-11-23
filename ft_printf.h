/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:38:44 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/23 18:39:06 by jthuy            ###   ########.fr       */
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
** def_params.c
*/
void	check_flags(char *flags, const char **str);
int		def_width(const char **str);

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
int		len_numb(int value, char len_sign);
int		len_unumb(unsigned int value);
char	len_sign(int value, char flags);
int		len_str(const char *str);
int		len_space(int width, const char **str, void *value, char flags);

/*
** conversion.c
*/
int		binto_oct(int value);
char	*binto_hex(int value, char index);
char	*binto_uhex(unsigned int value, char index);
// int		def_bitborder(int value);
int		def_bitborder(int value, char bit_count);
int		two_inpower(int power);

/*
** put_numbers.c
*/
void	put_sign(int value, char flags, int *amount);
void	put_abs(int value, char flags, int *amount);
// void	put_prefix(int value, char flags, int *amount);
void	put_prefix(char flags, int *amount);
void	put_uabs(unsigned int value, char flags, int *amount);

/*
** put_symbols.c
*/
void	put_char(char symbol, const char **str, int *amount);
int		put_freesmb(const char **str, int *amount);
void	put_space(int len_space, char flags, int *amount);
void	put_str(char const *str, int *amount);

#endif

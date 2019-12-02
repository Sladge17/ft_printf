/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:38:44 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/02 15:35:42 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		g_width;
int		g_accuracy;

/*
** ft_printf.c
*/

/*
** def_params.c
*/
void	check_flags(short *flags, const char **str);
void	def_width(short *flags, const char **str);
void	def_accuracy(short *flags, const char **str);
void	ft_atoi(int *param, const char **str);

/*
** find_flags.c
*/
char	find_minus(const char **str, short *flags);
char	find_plus(const char **str, short *flags);
char	find_space(const char **str, short *flags);
char	find_lattice(const char **str, short *flags);
char	find_zero(const char **str, short *flags);

/*
** def_lengths.c
*/
int		len_numb(int value);
int		len_unumb(unsigned int value);
char	len_sign(void *value, short flags);
int		len_str(const char *str);
int		len_symbols(const char **str, void *value, short *flags);

/*
** conversion.c
*/
void	binto_oct(void **value, char index);
void	binto_hex(void **value, char index);
void	def_bitborder(unsigned int *bitborder, int value, char bit_count);

/*
** put_numbers.c
*/
void	put_sign(void **value, short *flags, int *amount);
void	put_abs(int value, short flags, int *amount);
void	put_prefix(char *value, short flags, int *amount);
void	put_uabs(unsigned int value, short flags, int *amount);

/*
** put_symbols.c
*/
void	put_char(char symbol, const char **str, int *amount);
char	put_freesmb(const char **str, int *amount);
char	check_lastfreesmb(const char **str, int *amount);
void	put_space(const char **str, void *value, short *flags, int *amount);
void	put_zero(const char **str, void *value, short flags, int *amount);
void	put_str(char const *str, int *amount);

#endif

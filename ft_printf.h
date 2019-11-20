/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:38:44 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/20 15:26:30 by jthuy            ###   ########.fr       */
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
void	put_prefix(int *amount, int value_d, char flags);

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
// int		len_numb_abc(int value_d);
int		len_numb(int value_d, char len_sign);
int		len_unumb(unsigned int value_d);
// int		len_sign(int value_d, char flags);
char	len_sign(int value_d, char flags);
int		len_str(const char *str);
// int		len_space(char flags, int width, int len_symbols, int len_sign);
int		len_space(int width, int len_symbols);

/*
** conversion.c
*/
int		binto_oct(int value_d);
int		def_bitborder(int value_d);
int		two_inpower(int power);

/*
** put_symbols.c  <--- 7 functions
*/
void	put_char(char symbol, const char **str, int *amount);
int		put_freesmb(const char **str, int *amount);
void	put_abs(int n, int *amount);
void	put_uabs(unsigned int n, int *amount);
void	put_sign(int value_d, char flags, int *amount);
// void	put_space(int width, int value_d, char flags, int *amount);
void	put_space(int len_space, char flags, int *amount);
void	ft_putstr(char const *s, int *amount);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:38:44 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/21 17:57:04 by jthuy            ###   ########.fr       */
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
// void	put_prefix(int *amount, char flags);
void	put_prefix(int value, char flags, int *amount);

/*
** def_params.c
*/
char	check_flags(const char **str);
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
// void	*binto_oct(int value);
int		def_bitborder(int value);
int		two_inpower(int power);

/*
** put_symbols.c  <--- 7 functions
*/
void	put_char(char symbol, const char **str, int *amount);
int		put_freesmb(const char **str, int *amount);
// void	put_abs(int n, int *amount);
void	put_abs(int value, char flags, int *amount);
// void	put_uabs(unsigned int n, int *amount);
void	put_uabs(unsigned int value, char flags, int *amount);
void	put_sign(int value, char flags, int *amount);
void	put_space(int len_space, char flags, int *amount);
void	ft_putstr(char const *s, int *amount);


#endif

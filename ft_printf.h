/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:38:44 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/06 19:32:10 by jthuy            ###   ########.fr       */
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
void	check_flags(unsigned int *flags, const char **str);
void	def_width(unsigned int *flags, const char **str);
void	def_accuracy(unsigned int *flags, const char **str);
void	ft_atoi(int *param, const char **str);
char	def_fasttype(unsigned int *flags, const char **str);
void	def_modifier(unsigned int *flags, const char **str);
void	find_modsymb(unsigned int *flags, const char **str, short flag);
void	def_type(unsigned int *flags, const char **str);

/*
** find_flags.c
*/
char	find_minus(const char **str, unsigned int *flags);
char	find_plus(const char **str, unsigned int *flags);
char	find_space(const char **str, unsigned int *flags);
char	find_lattice(const char **str, unsigned int *flags);
char	find_zero(const char **str, unsigned int *flags);

/*
** def_lengths.c
*/
int		len_numb(int value);
int		len_unumb(unsigned int value);
char	len_sign(void **value, unsigned int *flags);
// int	len_sign(int value, unsigned int *flags);
int		len_str(const char *str);
int		len_symbols(void **value, unsigned int *flags);

/*
** conversion.c
*/
void	conversion(unsigned int *flags, void **value);
void	binto_oct(void **value);
void	binto_hex(void **value, char index);
void	def_bitborder(unsigned int *bitborder, int value, char bit_count);

/*
** put_numbers.c
*/
void	put_sign(void **value, unsigned int *flags, int *amount);
void	put_abs(void **value, unsigned int *flags, int *amount);
void	put_abs_int(int value, int *amount);
void	put_abs_short(short value, int *amount);
void	put_abs_char(char value, int *amount);
void	put_abs_lint(long int value, int *amount);
void	put_abs_llint(long long int value, int *amount);
void	put_prefix(void **value, unsigned int *flags, int *amount);
void	put_uabs(void **value, unsigned int *flags, int *amount);
void	put_uabs_llint(unsigned long long int value, int *amount);

/*
** put_symbols.c
*/
void	put_char(char symbol, const char **str, int *amount);
char	put_freesmb(const char **str, int *amount);
char	check_lastfreesmb(const char **str, int *amount);
void	put_space(void **value, unsigned int *flags, int *amount);
void	put_zero(void **value, unsigned int *flags, int *amount);
void	put_str(char const *string, unsigned int *flags, int *amount);

#endif

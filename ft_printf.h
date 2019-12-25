/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:38:44 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/25 17:16:26 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		g_width;
int		g_accuracy;
int		g_lenarg;

/*
** ft_printf.c
*/
void	shift_garbage(const char **str);
char	parsing(int *flags, const char **str);
char	exe_numstr(void **value, int *flags, const char **str, int *amount);

void	def_remainder(char **remainder, long double value_f, long int unit);
void	fix_float(long int *unit, char **remainder);
void	put_float(long int *unit, char **remainder, int *flags, int *amount);

char	exe_float(long double *value_f, int *flags, const char **str, int *amount);
char	exe_wsymb(void **value, int *flags, const char **str, int *amount);
void	exe_other(void **value, int *flags, const char **str, int *amount);
void	intrp(va_list *args, long double *value_f, void **value, int *flags);

/*
** def_params.c
*/
void	check_flags(int *flags, const char **str);
void	def_width(int *flags, const char **str);
void	def_accuracy(int *flags, const char **str);
void	ft_atoi(int *param, const char **str);
char	def_fasttype(int *flags, const char **str);
void	def_modifier(int *flags, const char **str);
void	find_modsymb(int *flags, const char **str, short flag);
void	def_type(int *flags, const char **str);

/*
** find_flags.c
*/
char	find_minus(const char **str, int *flags);
char	find_plus(const char **str, int *flags);
char	find_space(const char **str, int *flags);
char	find_lattice(const char **str, int *flags);
char	find_zero(const char **str, int *flags);

/*
** def_lengths.c
*/
// int		len_numb(int value);
int		len_numb(void **value, int *flags);
// int		len_unumb(unsigned int value);
int		len_unumb(unsigned long int value);
char	len_sign(void **value, int *flags);

char	len_sign_f(long double *value_f, int *flags);

int		len_str(const char *str);
// int		len_symbols(void **value, int *flags);
void	len_arg(void **value, int *flags);

/*
** conversion.c
*/
// void	conversion(int *flags, void **value);
void	conversion(void **value, int *flags);
void	binto_oct(void **value, int *flags);
void	binto_hex(void **value, int *flags, char index);
void	def_bitborder(unsigned long int *bitborder, void **value, int *flags);
void	def_bitborder_int(unsigned long int *bitborder, int value, char bit_count);
void	def_bitborder_short(unsigned long int *bitborder, short value, char bit_count);
void	def_bitborder_char(unsigned long int *bitborder, char value, char bit_count);
void	def_bitborder_lint(unsigned long int *bitborder, long int value, char bit_count);

/*
** put_numbers.c
*/
void	put_sign(void **value, int *flags, int *amount);

void	put_sign_f(long double *value_f, int *flags, int *amount);

void	put_abs(void **value, int *flags, int *amount);
void	put_abs_int(int value, int *amount);
void	put_abs_short(short value, int *amount);
void	put_abs_char(char value, int *amount);
// void	put_abs_lint(long int value, int *amount);
// void	put_abs_llint(long long int value, int *amount);
void	put_abs_lint(long int value, int *amount);
void	put_prefix(void **value, int *flags, int *amount);
void	put_uabs(void **value, int *flags, int *amount);
// void	put_uabs_llint(unsigned long long int value, int *amount);
void	put_uabs_lint(unsigned long int value, int *amount);

/*
** put_symbols.c
*/
void	put_char(char symbol, const char **str, int *amount);
char	put_freesmb(const char **str, int *amount);
char	check_lastfreesmb(const char **str, int *amount);
void	put_space(void **value, int *flags, int *amount);

void	put_space_f(long double *value_f, int *flags, int *amount);
void	def_lensymbols_f(int *len_symbols, long double *value_f);

void	def_lensymbols(int *len_symbols, void **value, int *flags);
void	put_zero(void **value, int *flags, int *amount);
void	put_str(char *value, int *flags, int *amount);

#endif

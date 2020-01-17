/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:38:44 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/17 13:27:00 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		g_flags;
int		g_width;
int		g_accuracy;
int		g_lenarg;

/*
** ft_printf.c
*/
void	shift_garbage(const char **str);
// char	parsing(int *flags, const char **str);

char	parsing(const char **str, va_list *args);

char	exe_numstr(void **value, const char **str, int *amt);
char	exe_wsymb(void **value, const char **str, int *amt);
void	exe_other(void **value, const char **str, int *amt);
void	intrp(va_list *args, long double *value_f, void **value);

/*
** def_params.c
*/
void	check_flags(const char **str);
// void	def_width(int *flags, const char **str);

void	def_width(const char **str, va_list *args);

// void	def_accuracy(int *flags, const char **str);

void	def_accuracy(const char **str, va_list *args);

void	ft_atoi(int *param, const char **str);
char	def_fasttype(const char **str);
void	def_modifier(const char **str);
void	find_modsymb(const char **str, short flag);
void	def_type(const char **str);

/*
** find_flags.c
*/
char	find_minus(const char **str);
char	find_plus(const char **str);
char	find_space(const char **str);
char	find_lattice(const char **str);
char	find_zero(const char **str);

/*
** execution_f.c
*/
char	exe_float(long double *value_f, const char **str, int *amt);
void	fixput_float(long int *unit, char **remainder, int *amt);
void	put_space_f(long double *value_f, int *amt);
void	def_lensymbols_f(int *len_symbols, long double *value_f);
void	put_sign_f(long double *value_f, int *amt);
void	def_remainder(char **remainder, long double value_f, long int unit);
void	fix_float(long int *unit, char **remainder);
void	put_float(long int *unit, char **remainder, int *amt);

/*
** def_lengths.c
*/
int		len_numb(void **value);
int		len_unumb(unsigned long int value);
char	len_sign(void **value);
char	len_sign_f(long double *value_f);
int		len_str(const char *str);
void	len_arg(void **value);

/*
** conversion.c
*/
void	conversion(void **value);
void	binto_oct(void **value);
void	binto_hex(void **value, char index);
void	def_bitend(unsigned long int *bitend, void **value);
void	def_bitend_int(unsigned long int *bitend, int value, char bitcnt);
void	def_bitend_short(unsigned long int *bitend, short value, char bitcnt);
void	def_bitend_char(unsigned long int *bitend, char value, char bitcnt);
void	def_bitend_lint(unsigned long int *bitend, long int value, char bitcnt);

/*
** put_numbers.c
*/
void	put_sign(void **value, int *amt);
void	put_abs(void **value, int *amt);
void	put_abs_int(int value, int *amt);
void	put_abs_short(short value, int *amt);
void	put_abs_char(char value, int *amt);
void	put_abs_lint(long int value, int *amt);
void	put_prefix(void **value, int *amt);
void	put_uabs(void **value, int *amt, int *g_flags);
void	put_uabs_lint(unsigned long int value, int *amt);

/*
** put_symbols.c
*/
void	put_char(char symbol, const char **str, int *amt);
char	put_freesmb(const char **str, int *amt);
char	check_lastfreesmb(const char **str, int *amt);
void	put_space(void **value, int *amt);
void	def_lensymbols(int *len_symbols, void **value);
void	put_zero(void **value, int *amt);
void	put_str(char *value, int *amt);
void	putcycle(char symbol, int border, int *amt);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:12:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/25 13:22:22 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>

int		ft_printf(const char *str, ...);

int		main()
{
	int		test;
	int		rez;
	
	char	c;
	char	*name;
	int		numb;
	// int		amount_std;
	// int		amount_cst;

	c = 'w';
	name = "School";
	numb = 42;

	test = 0;
	
	char	*test_simple_mix;

	test_simple_mix = "Hello World";
	
	test += 1;
	
	// int		a01;
	// int		a02;
	// int		a03;
	// int		a04;
	// int		a05;
	// int		a06;
	// int		a07;
	// int		a08;
	// int		a09;
	// int		a10;
	// int		a11;
	// int		a12;
	// int		free;
	
	
	
	printf("\n");
	printf("test %d  <----------\n", test);
	// rez = printf("%#8.3o", 8375);
	// rez = printf("%#8.5o", 34);
	// rez = printf("%#7o", 33);
	// rez = printf("%#3o", 0);
	// rez = printf("%#5.0o", 0);
	// rez = printf("%.20f",  0.999999999999999999990);
	// rez = printf("%.20f", 0.000000000000000000010);
	rez = printf("%.20f",        1.025978542436587568678);
	
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	// rez = ft_printf("%#8.3o", 8375);
	// rez = ft_printf("%#8.5o", 34);
	// rez = ft_printf("%#7o", 33);
	// rez = ft_printf("%#3o", 0);
	// rez = ft_printf("%#5.0o", 0);
	// rez = ft_printf("%.20f",  0.999999999999999999990);
	// rez = ft_printf("%.20f", 0.000000000000000000010);
	rez = ft_printf("%.20f",        1.025978542436587568678);
	
	printf("->%d\n", rez);

	return (0);
}
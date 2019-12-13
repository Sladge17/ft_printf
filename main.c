/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:12:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/13 22:01:26 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

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
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%5c", 42);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%5c", 42);
	printf("->%d\n", rez);

	return (0);
}
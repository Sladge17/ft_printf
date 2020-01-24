/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:12:02 by jthuy             #+#    #+#             */
/*   Updated: 2020/01/22 18:27:06 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>

int		ft_printf(const char *str, ...);

int		main()
// int		main(int argc, char **argv)
{
	int		test;
	int		rez;
	
	char	c;
	char	*name;
	int		numb;

	char	*q1;
	char	*q2;
	char	*q3;

	// q1 = "test1";
	// q2 = "test2";
	// q3 = "test3";

	q1 = NULL;

	c = 'w';
	name = "School";
	numb = 42;

	test = 0;
	
	char	*test_simple_mix;

	test_simple_mix = "Hello World";
	
	test += 1;

	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("test");
	
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("test");
	
	// write(1, "\e[0m", 4);
	printf("->%d\n", rez);

	// if (argc == 1)
	// 	return (0);
	// rez = ft_printf(argv[1]);
	// printf("->%d\n", rez);

	return (0);
}
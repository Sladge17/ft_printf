/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:12:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/11 15:47:31 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_printf(const char *str, ...);

int		main()
{
	int		test;
	int		rez;
	
	char	c;
	char	*name;
	int		numb;
	int		amount_std;
	int		amount_cst;

	c = 'w';
	name = "School";
	numb = 42;

	test = 0;
	
	test += 1;
	printf("test %d  <----------\n", test);
	rez = printf("%d\n%d\n%d\n", -126, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%d\n%d\n%d\n", -126, 0, 1258);
	printf("->%d\n", rez);
	
	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%+d\n%+d\n%+d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%+d\n%+d\n%+d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("% +d\n% +d\n% +d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("% +d\n% +d\n% +d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%6d\n%6d\n%6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%6d\n%6d\n%6d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%3d\n%3d\n%3d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%3d\n%3d\n%3d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%-6d\n%-6d\n%-6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%-6d\n%-6d\n%-6d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%+6d\n%+6d\n%+6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%+6d\n%+6d\n%+6d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%-+6d\n%-+6d\n%-+6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%-+6d\n%-+6d\n%-+6d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("% -6d\n% -6d\n% -6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("% -6d\n% -6d\n% -6d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("% +-6d\n% +-6d\n% +-6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("% +-6d\n% +-6d\n% +-6d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%06d\n%06d\n%06d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%06d\n%06d\n%06d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%03d\n%03d\n%03d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%03d\n%03d\n%03d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%-06d\n%-06d\n%-06d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%-06d\n%-06d\n%-06d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%+06d\n%+06d\n%+06d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%+06d\n%+06d\n%+06d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	
	// 
	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%0 6d\n%0 6d\n%0 6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%0 6d\n%0 6d\n%0 6d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%0-+6d\n%0-+6d\n%0-+6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%0-+6d\n%0-+6d\n%0-+6d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%0- 6d\n%0- 6d\n%0- 6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%0- 6d\n%0- 6d\n%0- 6d\n", -124, 0, 1258);
	printf("->%d\n", rez);

	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%+0- 6d\n%+0- 6d\n%+0- 6d\n", -124, 0, 1258);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%+0- 6d\n%+0- 6d\n%+0- 6d\n", -124, 0, 1258);
	printf("->%d\n", rez);


	
	
	// ft_printf("0#qw");

	
	// amount_std = printf("Hello %s %d\n", name, numb);
	// printf("%d\n", amount_std);
	// amount_cst = ft_printf("Hello %s %d\n", name, numb);
	// printf("%d\n", amount_cst);
	
	// func(5, 12, 34, 543, 3, 5);
	// func(5, 'w', 'o', 'r', 'l', 'd');
	// func(5, "world");
	// func(5, "one", "two", "three", "four", "five");
	return (0);
}
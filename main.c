/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:12:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/12/07 18:24:44 by jthuy            ###   ########.fr       */
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
	
	// //  ------[ TESTS 1 - 20 ]-------
	
	// test += 1;
	// printf("test %d  <----------\n", test);
	// rez = printf("Hello world\n");
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("Hello world\n");
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("Min int %d\n", -2147483648);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("Min int %d\n", -2147483648);
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%d\n%d\n%d\n", -126, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%d\n%d\n%d\n", -126, 0, 1258);
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+d\n%+d\n%+d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+d\n%+d\n%+d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("% +d\n% +d\n% +d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("% +d\n% +d\n% +d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%6d\n%6d\n%6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%6d\n%6d\n%6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%3d\n%3d\n%3d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%3d\n%3d\n%3d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%-6d\n%-6d\n%-6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%-6d\n%-6d\n%-6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+6d\n%+6d\n%+6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+6d\n%+6d\n%+6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%-+6d\n%-+6d\n%-+6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%-+6d\n%-+6d\n%-+6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("% -6d\n% -6d\n% -6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("% -6d\n% -6d\n% -6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("% +-6d\n% +-6d\n% +-6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("% +-6d\n% +-6d\n% +-6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%06d\n%06d\n%06d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%06d\n%06d\n%06d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%03d\n%03d\n%03d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%03d\n%03d\n%03d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%-06d\n%-06d\n%-06d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%-06d\n%-06d\n%-06d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+06d\n%+06d\n%+06d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+06d\n%+06d\n%+06d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%0 6d\n%0 6d\n%0 6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%0 6d\n%0 6d\n%0 6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%0-+6d\n%0-+6d\n%0-+6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%0-+6d\n%0-+6d\n%0-+6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%0- 6d\n%0- 6d\n%0- 6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%0- 6d\n%0- 6d\n%0- 6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+0- 6d\n%+0- 6d\n%+0- 6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+0- 6d\n%+0- 6d\n%+0- 6d\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// //  ------[ TESTS 21 - 39]-------
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("Min int %u\n", -2147483648);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("Min int %u\n", -2147483648);
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%u\n%u\n%u\n", -126, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%u\n%u\n%u\n", -126, 0, 1258);
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+u\n%+u\n%+u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+u\n%+u\n%+u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// //
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("% +u\n% +u\n% +u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("% +u\n% +u\n% +u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%6u\n%6u\n%6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%6u\n%6u\n%6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%3u\n%3u\n%3u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%3u\n%3u\n%3u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%-6u\n%-6u\n%-6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%-6u\n%-6u\n%-6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+6u\n%+6u\n%+6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+6u\n%+6u\n%+6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%-+6u\n%-+6u\n%-+6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%-+6u\n%-+6u\n%-+6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("% -6u\n% -6u\n% -6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("% -6u\n% -6u\n% -6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("% +-6u\n% +-6u\n% +-6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("% +-6u\n% +-6u\n% +-6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%06u\n%06u\n%06u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%06u\n%06u\n%06u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%03u\n%03u\n%03u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%03u\n%03u\n%03u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%-06u\n%-06u\n%-06u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%-06u\n%-06u\n%-06u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+06u\n%+06u\n%+06u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+06u\n%+06u\n%+06u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%0 6u\n%0 6u\n%0 6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%0 6u\n%0 6u\n%0 6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%0-+6u\n%0-+6u\n%0-+6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%0-+6u\n%0-+6u\n%0-+6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%0- 6u\n%0- 6u\n%0- 6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%0- 6u\n%0- 6u\n%0- 6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+0- 6u\n%+0- 6u\n%+0- 6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+0- 6u\n%+0- 6u\n%+0- 6u\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	
	// //  ------[ TESTS 40]-------

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%o\n", 100);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%o\n", 100);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("Min int %o\n", -2147483648);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("Min int %o\n", -2147483648);
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%o\n%o\n%o\n", -126, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%o\n%o\n%o\n", -126, 0, 1258);
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+o\n%+o\n%+o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+o\n%+o\n%+o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("% +o\n% +o\n% +o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("% +o\n% +o\n% +o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%6o\n%6o\n%6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%6o\n%6o\n%6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%3o\n%3o\n%3o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%3o\n%3o\n%3o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%-6o\n%-6o\n%-6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%-6o\n%-6o\n%-6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+6o\n%+6o\n%+6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+6o\n%+6o\n%+6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%-+6o\n%-+6o\n%-+6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%-+6o\n%-+6o\n%-+6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("% -6o\n% -6o\n% -6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("% -6o\n% -6o\n% -6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("% +-6o\n% +-6o\n% +-6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("% +-6o\n% +-6o\n% +-6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%06o\n%06o\n%06o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%06o\n%06o\n%06o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%03o\n%03o\n%03o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%03o\n%03o\n%03o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%-06o\n%-06o\n%-06o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%-06o\n%-06o\n%-06o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+06o\n%+06o\n%+06o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+06o\n%+06o\n%+06o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	
	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%0 6o\n%0 6o\n%0 6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%0 6o\n%0 6o\n%0 6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%0-+6o\n%0-+6o\n%0-+6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%0-+6o\n%0-+6o\n%0-+6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%0- 6o\n%0- 6o\n%0- 6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%0- 6o\n%0- 6o\n%0- 6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%+0- 6o\n%+0- 6o\n%+0- 6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%+0- 6o\n%+0- 6o\n%+0- 6o\n", -124, 0, 1258);
	// printf("->%d\n", rez);

	// test += 1;
	// printf("\n");
	// printf("test %d  <----------\n", test);
	// rez = printf("%#o\n%#o\n%#o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	// printf("---\n");
	// fflush(NULL);
	// rez = ft_printf("%#o\n%#o\n%#o\n", -124, 0, 1258);
	// printf("->%d\n", rez);
	
	test += 1;
	printf("\n");
	printf("test %d  <----------\n", test);
	rez = printf("%llX", 429496729);
	printf("->%d\n", rez);
	printf("---\n");
	fflush(NULL);
	rez = ft_printf("%llX", 429496729);
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
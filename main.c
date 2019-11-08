/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:12:02 by jthuy             #+#    #+#             */
/*   Updated: 2019/11/08 13:06:25 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_printf(const char *str, ...);

int		main()
{
	char	c;
	char	*name;
	int		numb;
	int		amount_std;
	int		amount_cst;

	c = 'w';
	name = "School";
	numb = 42;
	
	printf("%+6d\n%+6d\n%+6d\n", -126, 0, 1258);
	printf("\n");
	ft_printf("%+6d\n%+6d\n%+6d\n", -126, 0, 1258);
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
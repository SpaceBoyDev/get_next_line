/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:27:41 by darmarti          #+#    #+#             */
/*   Updated: 2024/11/17 20:48:55 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	zuzumba;
	int	c;
	int	empty;
	int	one_char;
	int	one_line_no_nl;
	int	only_nl;
	int	loops;

	loops = 3;
	zuzumba = open("zuzumba.txt", O_RDONLY);
	c = open("main_get_next_line.c", O_RDONLY);
	empty = open("empty.txt", O_RDONLY);
	one_char = open("1char.txt", O_RDONLY);
	one_line_no_nl = open("one_line_no_nl.txt", O_RDONLY);
	only_nl = open("only_nl.txt", O_RDONLY);
	while (loops > 0)
	{
		printf("%s", get_next_line(one_line_no_nl));
		--loops;
	}
	return (0);
}

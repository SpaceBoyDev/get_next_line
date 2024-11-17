/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:27:41 by darmarti          #+#    #+#             */
/*   Updated: 2024/11/14 21:33:19 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	zuzumba;
	int	c;
	int	empty;
	int	one_char;
	int	loops;

	loops = 2;
	zuzumba = open("zuzumba.txt", O_RDONLY);
	c = open("main_get_next_line.c", O_RDONLY);
	empty = open("empty.txt", O_RDONLY);
	one_char = open("1char.txt", O_RDONLY);
	while (loops > 0)
	{
		printf("%s", get_next_line(one_char));
		--loops;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:27:41 by darmarti          #+#    #+#             */
/*   Updated: 2024/10/28 18:04:03 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	fd2;
	int	fd3;
	int	loops;

	loops = 20;
	fd = open("zuzumba.txt", O_RDONLY);
	fd2 = open("main_get_next_line.c", O_RDONLY);
	fd3 = open("empty.txt", O_RDONLY);
	while (loops > 0)
	{
		printf("%s", get_next_line(fd));
		--loops;
	}
	return (0);
}

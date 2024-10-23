/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:27:41 by darmarti          #+#    #+#             */
/*   Updated: 2024/10/23 17:55:48 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	fd2;
	int	loops;

	loops = 36;
	fd = open("zuzumba.txt", O_RDONLY);
	fd2 = open("main_get_next_line.c", O_RDONLY);
	while (loops > 0)
	{
		printf("%s", get_next_line(fd2));
		--loops;
	}

	// get_next_line(fd);

	//printf("%s", get_next_line(fd2));

	return (0);
}

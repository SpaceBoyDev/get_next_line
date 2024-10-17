/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:25:23 by darmarti          #+#    #+#             */
/*   Updated: 2024/10/17 19:06:35 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*all_lines[1024];
	char		*line;
	char		*buffer;
	int			bytes_read;

	buffer = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!all_lines[fd])
	{
		all_lines[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		printf(">BUMA");
	}
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !buffer || !all_lines[fd])
		return (NULL);

	printf("\nfd -> %d\n\n", fd);
	line = ft_strjoin(NULL, all_lines[fd]);
	bytes_read = 1;
	while(!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		//if (!ft_strchr(buffer, '\n'))
			line = ft_strjoin(line, buffer);
	}

	free(buffer);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:25:23 by darmarti          #+#    #+#             */
/*   Updated: 2024/10/21 20:23:14 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cleanbuffer(char *buffer)
{
	char	*clean_buffer;
	size_t	i;

	i = 0;
	while (buffer[i] != '\n')
		++i;
	clean_buffer = ft_calloc(i + 2, sizeof(char));
	if (!clean_buffer)
		return (NULL);
	i = 0;
	while (buffer[i - 1] != '\n')
	{
		clean_buffer[i] = buffer[i];
		++i;
	}
	return (clean_buffer);
}

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
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while(!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		if (ft_strchr(buffer, '\n'))
		{
			printf("Buffer -> %s\nBufferC ->%s\n", buffer, ft_cleanbuffer(buffer));
			line = ft_strjoin(line, ft_cleanbuffer(buffer));
		}
		else
			line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

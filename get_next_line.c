/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:25:23 by darmarti          #+#    #+#             */
/*   Updated: 2024/10/22 21:39:05 by dario            ###   ########.fr       */
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

char	*ft_clean_last_buffer(char *buffer)
{
	char	*new_last_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] != '\n')
		++i;
	++i;
	new_last_buffer = ft_calloc((BUFFER_SIZE - i + 1), sizeof(char));
	if (!new_last_buffer)
		return (NULL);
	j = 0;
	while (buffer[i] != '\0')
		new_last_buffer[j++] = buffer[i++];
	printf("\n\nnew_last_buffer -> %s\n\n", new_last_buffer);
	return (new_last_buffer);
}

char	*get_next_line(int fd)
{
	static char		*last_buffer[1024];
	char			*line;
	char			*buffer;
	int				bytes_read;

	if (!last_buffer[fd])
		last_buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !buffer || !last_buffer)
		return (NULL);
	//printf("\nfd -> %d\n\n", fd);
	line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	//line = ft_strjoin(NULL, last_buffer[fd]);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		if (ft_strchr(buffer, '\n'))
		{
			line = ft_strjoin(line, ft_cleanbuffer(buffer));
			//printf("BufferC ->%s\nBufferL ->%s\n\n", ft_cleanbuffer(buffer), ft_clean_last_buffer(buffer));
		}
		else
			line = ft_strjoin(line, buffer);
	}
	last_buffer[fd] = (NULL, buffer);
	last_buffer[fd] = ft_clean_last_buffer(buffer);
	free(buffer);
	return (line);
}

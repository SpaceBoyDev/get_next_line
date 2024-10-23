/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:25:23 by darmarti          #+#    #+#             */
/*   Updated: 2024/10/23 17:47:29 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cleanline(char *line)
{
	char	*clean_line;
	size_t	i;

	i = 0;
	while (line[i] != '\n')
		++i;
	clean_line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!clean_line)
		return (NULL);
	i = 0;
	while (line[i] != '\n')
	{
		clean_line[i] = line[i];
		++i;
	}
	clean_line[i] = '\n';
	return (clean_line);
}

// char	*ft_cleanbuffer(char *buffer)
// {
// 	char	*clean_buffer;
// 	size_t	i;

// 	i = 0;
// 	while (buffer[i] != '\n')
// 		++i;
// 	clean_buffer = ft_calloc(i + 2, sizeof(char));
// 	if (!clean_buffer)
// 		return (NULL);
// 	i = 0;
// 	while (buffer[i - 1] != '\n')
// 	{
// 		clean_buffer[i] = buffer[i];
// 		++i;
// 	}
// 	return (clean_buffer);
// }

char	*ft_clean_last_buffer(char *buffer)
{
	char	*new_last_buffer;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (NULL);
	len = ft_strlen(buffer);
	i = 0;
	while (buffer[i] != '\n')
		++i;
	++i;
	new_last_buffer = ft_calloc((len - i + 1), sizeof(char));
	if (!new_last_buffer)
		return (NULL);
	j = 0;
	while (buffer[i] != '\0')
		new_last_buffer[j++] = buffer[i++];
	//printf("\n\nnew_last_buffer -> %s\n\n", new_last_buffer);
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
	//line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_strjoin(NULL, last_buffer[fd]);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0 && !ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		line = ft_strjoin(line, buffer);
		last_buffer[fd] = ft_strjoin(last_buffer[fd], buffer);
	}
	line = ft_cleanline(line);
	//line = ft_strjoin(line, ft_cleanbuffer(buffer));
	//last_buffer[fd] = (NULL, buffer);
	last_buffer[fd] = ft_clean_last_buffer(last_buffer[fd]);
	free(buffer);
	return (line);
}

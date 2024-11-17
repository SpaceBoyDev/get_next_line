/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:25:23 by darmarti          #+#    #+#             */
/*   Updated: 2024/11/17 19:41:39 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_null(char **buffer, char **new_line)
{
	if (*new_line)
	{
		free(*new_line);
		*new_line = NULL;
	}
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

static void	ft_clean(char *line, char *clean_line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		clean_line[i] = line[i];
		++i;
	}
	if (line[i] == '\n')
		clean_line[i] = '\n';
	else
		clean_line[i] = '\0';
}

static char	*ft_cleanline(char *line, char **last_buffer)
{
	char	*clean_line;
	size_t	i;

	i = 0;
	if (line[0] == '\0')
	{
		if (*last_buffer)
		{
			free(*last_buffer);
			*last_buffer = NULL;
		}
		free(line);
		line = NULL;
		//printf("\nHOLA\n");
		return (NULL);
	}
	while (line[i] != '\n' && line[i])
		++i;
	clean_line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!clean_line)
		return (free(line), NULL);
	ft_clean(line, clean_line);
	free(line);
	line = NULL;
	return (clean_line);
}

static char	*ft_clean_last_buffer(char *buffer) //DA PROBLEMAS
{
	char	*new_last_buffer;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (NULL);
	len = ft_strlen(buffer);
	//printf("\nLen = %li\n", len);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		++i;
	//++i;
	//printf("\ni = %li\n", i);
	new_last_buffer = ft_calloc((len - i + 1), sizeof(char));
	if (!new_last_buffer)
		return (NULL);
	j = 0;
	while (buffer[i] != '\0')
		new_last_buffer[j++] = buffer[i++];
	free(buffer);
	buffer = NULL;
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
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !buffer || !last_buffer[fd])
		return (free_null(&buffer, &last_buffer[fd]));
	line = ft_strjoin(NULL, last_buffer[fd], 0);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0 && !ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), line = NULL,
				free_null(&buffer, &last_buffer[fd]));
		if (bytes_read == 0)
			break ;
		// printf("\nReadBytes -> %i\n", bytes_read);
		line = ft_strjoin(line, buffer, bytes_read);
		last_buffer[fd] = ft_strjoin(last_buffer[fd], buffer, bytes_read);
		// size_t	prueba = 0;
		// while (line[prueba])
		// {
		// 	printf("char num %li es %c\n", prueba, line[prueba]);
		// 	++prueba;
		// }
		//HASTA AQUI, LAST BUFFER Y LINE NO TIENEN BASURA
	}
	// printf("\nPreCheckeando line...\n");
	//size_t	prueba = 0;
	// while (line[prueba])
	// 	printf("char num %li es %c\n", prueba++, line[prueba]);

	last_buffer[fd] = ft_clean_last_buffer(last_buffer[fd]);
	// while (last_buffer[fd][prueba])
	// {
	// 	printf("char num %li es %c\n", prueba, last_buffer[fd][prueba]);
	// 	++prueba;
	// }
	line = ft_cleanline(line, &last_buffer[fd]);
	//printf("\nCheckeando line...\n");
	// prueba = 0;
	// while (line[prueba])
	// 	printf("char num %li es %c\n", prueba++, line[prueba]);
	return (free(buffer), line);
}

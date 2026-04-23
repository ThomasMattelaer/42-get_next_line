/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-21 10:40:24 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-21 10:40:24 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*end_of_read(char *line, char *buffer, int bytes_read)
{
	buffer[0] = '\0';
	if (bytes_read < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static void	add_to_line(char *buffer, char **line)
{
	char	*tmp;

	if (!*line)
		*line = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(*line, buffer);
		free(*line);
		*line = tmp;
	}
}

static char	*extract_line(char *buffer, char *line)
{
	int		index;
	int		n;
	int		p;
	char	*substr;
	char	*res;

	index = find_char_index(buffer, '\n');
	if (index < 0)
		return (NULL);
	substr = ft_substr(buffer, 0, index + 1);
	if (!line)
		res = ft_strdup(substr);
	else
		res = ft_strjoin(line, substr);
	free (substr);
	free (line);
	n = ft_strlen(buffer) - (index + 1);
	p = -1;
	while (++p < n)
		buffer[p] = buffer[index + 1 + p];
	buffer[n] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (buffer[fd][0] != '\0')
	{
		if (find_char_index(buffer[fd], '\n') >= 0)
			return (extract_line(buffer[fd], line));
		line = ft_strdup(buffer[fd]);
		buffer[fd][0] = '\0';
	}
	while (1)
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read <= 0)
			return (end_of_read(line, buffer[fd], bytes_read));
		buffer[fd][bytes_read] = '\0';
		if (find_char_index(buffer[fd], '\n') >= 0)
			return (extract_line(buffer[fd], line));
		add_to_line(buffer[fd], &line);
	}
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	char	*next_line;
// 	char	*second_line;
// 	int		count;

// 	count = 0;
// 	fd = open("example.txt", O_RDONLY);
// 	fd2 = open("example2.txt", O_RDONLY);
// 	while(1)
// 	{
// 		next_line = get_next_line(fd);
// 		second_line = get_next_line(fd2);
// 		if (next_line == NULL)
// 			break;
// 		count++;
// 		printf("[%d]:%s", count, next_line);
// 		printf("[%d]:%s", count, second_line);
// 		free(next_line);
// 		next_line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }

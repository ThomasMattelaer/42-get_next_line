/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-16 08:34:44 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-16 08:34:44 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			bytes_read;
	int			index;

	line = NULL;
	// check if buufer contains '\0' (specifities to be determined)
		// join buff to line

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	if(bytes_read >= 0) //a checker in case of EOF
		return (NULL);
	while (bytes_read > 0)
	{
		index = find_char_index(buffer, '\n');
		if (index >= 0)
		{
			line = ft_substr(buffer, 0, index + 1); // include the \n
			int n = bytes_read - (index + 1);
			int p = -1;
			while(++p < n)
				buffer[p] = n;
			buffer[n] = '\0';
			return (line);
		}
		ft_strjoin(line, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);

	}
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	char		*buffer;
// 	char		*before_s;
// 	char		*tmp;
// 	static char	*rest;
// 	int			index;

// 	index = 0;
// 	tmp = rest;
// 	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if(!buffer)
// 		return (NULL);
// 	while (bytes_read >= 0)
// 	{
// 		if(bytes_read <= 0)
// 		{
// 			if (rest)
// 			{
// 				tmp = rest;
// 				rest = NULL;
// 				return (tmp);
// 			}
// 			free(buffer);
// 			return (NULL);
// 		}
// 		if(!tmp)
// 			tmp = buffer;
// 		else
// 			tmp = ft_strjoin(tmp,buffer);
// 		index = find_char_index(tmp, '\n');
// 		if(index >= 0)
// 		{
// 			if(rest)
// 				before_s = ft_strjoin(rest, ft_substr(tmp, 0, index + 1));
// 			else
// 				before_s =  ft_substr(tmp, 0, index + 1);
// 			free(rest);
// 			rest = ft_substr(tmp, index + 1, ft_strlen(tmp) - (index + 1));
// 			free(tmp);
// 			free(buffer);
// 			return (before_s);
// 		}
// 	}
// 	return (buffer);
// }
#include <fcntl.h>

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("example.txt", O_RDONLY);
//   next_line = get_next_line(fd);

  while(1)
  {
	  next_line = ft_read_fd(fd);
	  if(next_line == NULL)
	  	break;
	  count++;
	  printf("[%d]:%s", count, next_line);
	  free(next_line);
	  next_line = NULL;
}
  close(fd);
  return (0);
}

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

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*before_s;
	static int	bytes_read;
	size_t		index;

	index = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	if(!buffer)
		return (NULL);
	while (index == 0)
	{

		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		index = find_char_index(buffer, '\n');
	}
	before_s = ft_substr(buffer, 0, index + 1);
	return (before_s);
}
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("example.txt", O_RDONLY);
  while(1)
  {
	  next_line = get_next_line(fd);
	  if(next_line == NULL)
	  	break;
	  count++;
	  printf("[%d]:%s\n", count, next_line);
	  next_line = NULL;
}
  close(fd);
  return (0);
}

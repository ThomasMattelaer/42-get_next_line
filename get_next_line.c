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

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*before_s;
	char		*tmp;
	static char	*after_s;
	int			bytes_read;
	size_t		index;

	after_s = "";
	bytes_read = 1;
	index = 0;
	tmp = "";
	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	if(!buffer)
		return (NULL);
	while (bytes_read >= 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		printf("BytesRead: %d\n", bytes_read);
		if(bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		index = find_char_index(tmp, '\n');
		if(index == 0)
		{
			tmp = ft_strjoin(tmp,buffer);
		}
		printf("tmp: %s\n", tmp);
		if(index != 0)
		{
			printf("Index: %zu\n", index);
			before_s =  ft_substr(tmp, 0, index);
			free(tmp);
			return (before_s);
		}
	}
	return(buffer);
}
#include <fcntl.h>

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("example.txt", O_RDONLY);
	printf("[%d]\n", count);

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

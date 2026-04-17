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
	int			index;

	bytes_read = 1;
	index = 0;
	tmp = "";
	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	if(!buffer)
		return (NULL);
	while (bytes_read >= 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read <= 0)
		{
			if (after_s)
			{
				tmp = after_s;
				after_s = NULL;
				return (tmp);
			}
			free(buffer);
			return (NULL);
		}
		tmp = ft_strjoin(tmp,buffer);
		index = find_char_index(tmp, '\n');
		if(index >= 0)
		{
			if(after_s)
				before_s = ft_strjoin(after_s, ft_substr(tmp, 0, index + 1));
			else
				before_s =  ft_substr(tmp, 0, index + 1);
			free(after_s);
			after_s = ft_substr(tmp, index + 1, 100);
			free(tmp);
			return (before_s);
		}
	}
	return(buffer);
}
#include <fcntl.h>
//test
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

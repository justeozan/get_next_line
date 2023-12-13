/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:41 by justo             #+#    #+#             */
/*   Updated: 2023/12/13 13:49:27 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int     check_buffer(char *buffer)
{
	int	i;

	i = 0;

	while (i <= BUFFER_SIZE)
	{
		if (buffer[i] == '\0')
			return (-1);
		if (buffer[i] == '\n')
			return (0);
	}
	return (1);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	dl = 0;
	sl = 0;
	i = 0;
	while (dst[dl] != '\0' && dl < size)
		dl++;
	while (src[sl] != '\0')
		sl++;
	if (size == 0 || dl == size)
		return (size + sl);
	while (src[i] != '\0' && dl + i < size - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}

char	*run(char *buffer, char *line)
{
	int	i;
	int	read_continue;

	i = 0;
	read_continue = 1;
	while (read_continue == 1)
	{
		strlcat(line, buffer, strlen(line) + i);
		if (check_buffer < 1)
			read_continue == 0;
		i++;
	}
	printf("%s\n", line);
	return (line);
	while (i <= (BUFFER_SIZE + 1))
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			
			
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;


	line = NULL;
	line = str_init();
	if (fd < 0 || read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	return(run(buffer));
}

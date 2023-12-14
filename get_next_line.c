/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:41 by justo             #+#    #+#             */
/*   Updated: 2023/12/14 13:53:54 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*str_init(char *s)
{

	s = (char *)malloc(sizeof(char) * 1);
	if (!s)
		return (NULL);
	s[0] = '\0';
	return (s);
}

int	check_buffer(char *buffer)
{
	int	i;

	i = 0;

	while (i <= BUFFER_SIZE)
	{
		if (buffer[i] == '\0')
			return (-1);
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*run(char *buffer, char *line)
{
	int	read_continue;

	read_continue = 1;
	while (read_continue == 1)
	{
		// ft_strlcat_gnl(line, buffer, ft_strlen_gnl(line) + BUFFER_SIZE + 1);
		line = ft_strjoin_gnl(line, buffer);
		if (check_buffer(buffer) < 1)
			read_continue = 0;
		printf("step 11, read_continue = %d\n", read_continue);
	}
	printf("%s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	line = str_init(line);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	if (fd < 0 || read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	if (buffer == NULL)
		return (NULL);
	line = run(buffer, line);
	printf("final step\n");
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char	*line;
	int		fd;

	if (argc != 2)
		return 1;
	// printf("%s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return 1;
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("line = %s", line);
	// 	free(line);
	// }
	line = get_next_line(fd);
	printf("\nline = %s", line);
	return 0;
}
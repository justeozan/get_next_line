/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:41 by justo             #+#    #+#             */
/*   Updated: 2023/12/13 17:16:25 by ozasahin         ###   ########.fr       */
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
	}
	return (1);
}

size_t	ft_strlcat_gnl(char *dst, char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	i = 0;
	printf("step 5\n");
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	printf("step 6\n");
	printf("src[src_len] = %c\n", src[src_len]);
	while (src[src_len] != '\n' || src[src_len] != '\0')
	{
		printf("src[src_len] = %c\n", src[src_len]);
		src_len++;
	}
	printf("step 7\n");
	if (size == 0 || dst_len == size)
		return (size + src_len);
	while ((src[i] != '\n' || src[i] != '\0') && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*run(char *buffer, char *line)
{
	int	read_continue;

	read_continue = 1;
	printf("step 3\n");
	while (read_continue == 1)
	{
		printf("step 4\n");
		ft_strlcat_gnl(line, buffer, ft_strlen(line) + BUFFER_SIZE + 1);
		if (check_buffer(buffer) < 1)
			read_continue = 0;
	}
	printf("%s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	printf("step 0\n");
	line = NULL;
	line = str_init(line);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	printf("step 1\n");
	if (fd < 0 || read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	if (buffer == NULL)
		return (NULL);
	printf("step 2\n");
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
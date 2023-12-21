/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:41 by justo             #+#    #+#             */
/*   Updated: 2023/12/21 14:19:50 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_the_line(char *line, char *buffer, int len)
{
	char	*new_line;
	int		i;
	int		j;

	new_line = malloc(sizeof(char) * (len + 1 + ft_strlen_gnl(line)));
	if (!new_line)
		return (free(line), NULL);
	i = -1;
	while (line[++i])
		new_line[i] = line[i];
	free(line);
	j = 0;
	while (j < len)
	{
		new_line[i] = buffer[j];
		i++;
		j++;
	}
	new_line[i] = '\0';
	return (new_line);
}

size_t	there_is_a_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (0);
}

int	update_gnl(char *newbuffer, char *buffer, char **line)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		newbuffer[i] = buffer[i];
		i++;
	}
	newbuffer[i] = '\0';
	*line = extract_the_line(*line, newbuffer, ft_strlen_gnl(newbuffer));
	if (!*line)
		return (-1);
	return (1);
}

char	*run_read(int fd, char *line, char *buffer)
{
	int	byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			break ;
		buffer[byte_read] = 0;
		line = extract_the_line(line, buffer, ft_strlen_gnl(buffer));
		if (!line)
			return (NULL);
		if ((there_is_a_line(line) > 0 || byte_read == 0) && line[0] != 0)
			return (line);
	}
	buffer[0] = '\0';
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_id	buffer_memory[MAX_ID];
	char		*line;
	char		*buffer;

	if (fd < 0 || MAX_ID < 1 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	line = str_init(line);
	if (!line)
		return (NULL);
	buffer = buffer_init(fd, buffer_memory);
	if (!buffer)
		return (NULL);
	if (update_gnl(buffer, &buffer[there_is_a_line(buffer)], &line) < 0)
		return (free(line), NULL);
	if (there_is_a_line(line) > 0)
		return (line);
	return (run_read(fd, line, buffer));
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(int argc, char **argv)
// {
// 	char	*line;
// 	int		fd;

// 	if (argc != 2)
// 		return 1;
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		return 1;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("line = %s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return 0;
// }
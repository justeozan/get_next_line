/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:41 by justo             #+#    #+#             */
/*   Updated: 2023/12/14 18:02:30 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_the_line(char *line, char *buffer, int	len) // OK
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

int	there_is_a_line(char *str) //OK
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (0);
}

// int	check_buffer(char *buffer)
// {
// 	int	i;

// 	i = 0;

// 	while (i <= BUFFER_SIZE)
// 	{
// 		if (buffer[i] == '\0')
// 			return (-1);
// 		if (buffer[i] == '\n')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// char	*run(char *buffer, char *line)
// {
// 	int	read_continue;

// 	read_continue = 1;
// 	while (read_continue == 1)
// 	{
// 		// ft_strlcat_gnl(line, buffer, ft_strlen_gnl(line) + BUFFER_SIZE + 1);
// 		if (check_buffer(buffer) < 1)
// 			read_continue = 0;
		
// 		line = ft_strjoin_gnl(line, buffer);
// 		buffer = ft_rebuffing(buffer);
// 		// if (check_buffer(buffer) < 1)
// 		// 	read_continue = 0;
// 		// printf("step 11, read_continue = %d\n", read_continue);
// 	}
// 	printf("%s\n", line);
// 	return (line);
// }


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
	if (!line)
		return (-1);														//error when updating
	return (1);																//gnl has been updated
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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	line = str_init(line);
	if (!line)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 1 
		|| update_gnl(buffer, &buffer[there_is_a_line(buffer)], &line) < 0)	//update the line and the buffer if needed.
		return (free(line), NULL);
	if (there_is_a_line(line) > 0)											// check if there's a line in 'line'.
		return (line);														//if yes, return this line.
	return (run_read(fd, line, buffer));									// if not, return the line we're gonna extract from the buffer
}







//--------------------------------------------



#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
		return 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line = %s", line);
		free(line);
	}
	close(fd);
	return 0;
}
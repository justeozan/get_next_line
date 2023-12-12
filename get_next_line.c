/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:41 by justo             #+#    #+#             */
/*   Updated: 2023/12/12 15:26:45 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static char	buffer[300];
	static int	read_result;
	int			i;
	char		*line;

	i = 0;
	if (buffer[i] != '\0')
	{
		line = ft_strjoin(line, buffer);
	}
	read_result = read(fd, buffer, 300);
	if (read_result == -1 || read_result == 0)
		return (NULL);
	while (i <= 300)
	{
		if (buffer[i] == '\n')
		{
			line = ft_strjoin(line, buffer);
			ft_memmove(buffer, buffer);
			return (line);
		}
		i++;
	}
	get_next_line(fd);
}

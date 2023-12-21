/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:43 by justo             #+#    #+#             */
/*   Updated: 2023/12/21 14:19:33 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*str_init(char *s)
{
	s = (char *)malloc(sizeof(char) * 1);
	if (!s)
		return (NULL);
	s[0] = '\0';
	return (s);
}

char	*buffer_init(int id, t_id *buffer_memory)
{
	int	i;

	i = 0;
	id++;
	while (i < MAX_ID && buffer_memory[i].id != id)
	{
		if (buffer_memory[i].id == 0)
		{
			buffer_memory[i].id = id;
			return (buffer_memory[i].buffer);
		}
		i++;
	}
	if (buffer_memory[i].id == id)
		return (buffer_memory[i].buffer);
	return (NULL);
}

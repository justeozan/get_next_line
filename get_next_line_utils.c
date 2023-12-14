/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:43 by justo             #+#    #+#             */
/*   Updated: 2023/12/14 17:57:04 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> // ATTENTION !!!!!!!!!!!!!!!!!!!!!!!!!!!!!11

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
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

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *line, char *buffer)
{
	char	*str;
	int		l;

	if (!line || !buffer)
		return (NULL);
	l = ft_strlen_gnl(line) + ft_strlen_gnl(buffer);
	printf("l = %d", l);
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, line, ft_strlen_gnl(line) + 1);
	ft_strlcat(str, buffer, l + 1);
	return (str);
	
	// i = 0;
	// while (line[i])
	// {
	// 	str[i] = line[i];
	// 	i++;
	// }
	// while (buffer[i])
	// {
	// 	str[i] = buffer[i];
	// 	i++;
	// }
	// str[i] = '\0';
	// return (str);
}

// char	*ft_rebuffing(char *buffer)
// {
// 	char	*new_buffer;
// 	int		i;
// 	int		j;

// 	new_buffer = NULL;
// 	str_init(new_buffer);
// 	if (new_buffer == NULL)
// 	{
// 		free(new_buffer);
// 		return (NULL);
// 	}
// 	i = ft_strlen_gnl(buffer) + 1;
// 	j = 0;
// 	while (buffer[i] != '\n' && buffer[i] != '\0')
// 	{
// 		new_buffer[j] = buffer[i];
// 		i++;
// 		j++;
// 	}
// 	if ()
	
// }

char	*str_init(char *s)
{
	s = (char *)malloc(sizeof(char) * 1);
	if (!s)
		return (NULL);
	s[0] = '\0';
	return (s);
}

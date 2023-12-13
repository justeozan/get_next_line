/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:43 by justo             #+#    #+#             */
/*   Updated: 2023/12/13 13:25:15 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_slice_gnl(int flag, char *buffer, int size)
// {
// 	int		i;
// 	char	*new_str;

// 	i = 0;
// 	new_str = malloc
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;	
	if (dest == 0 && src == 0 && n > 0)
		return (0);
	if (dest < src)
		ft_memcpy(d, s, n);
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_create_str(char *line, char *buffer)
{
	char	*new_str;
	int		l;

	l = ft_strlen(line);
	l += ft_strlen(buffer);
	new_str = (char *)malloc(sizeof(char) * (l + 1));
	if (!new_str)
		return (0);
	return (new_str);
}

char	*ft_strjoin_gnl(char *line, char *buffer)
{
	char	*str;
	int		i;

	str = ft_create_str(line, buffer);

	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	while (buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

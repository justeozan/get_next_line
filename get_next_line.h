/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:22:44 by justo             #+#    #+#             */
/*   Updated: 2023/12/13 17:09:31 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

# include <unistd.h>
# include <stdlib.h>

//in gnl
int		check_buffer(char *buffer);
size_t	ft_strlcat_gnl(char *dst, char *src, size_t size);
char	*run(char *buffer, char *line);
char	*get_next_line(int fd);

//in gnl_utils
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_strlen(char *str);
char	*ft_create_str(char *line, char *buffer);
char	*ft_strjoin_gnl(char *line, char *buffer);

#endif
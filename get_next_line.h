/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:22:44 by justo             #+#    #+#             */
/*   Updated: 2023/12/21 11:27:54 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*extract_the_line(char *line, char *buffer, int	len);
int		there_is_a_line(char *str);
int		update_gnl(char *newbuffer, char *buffer, char **line);
char	*run_read(int fd, char *line, char *buffer);
char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
char	*str_init(char *s);

#endif
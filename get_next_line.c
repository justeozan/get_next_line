/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justo <justo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:41 by justo             #+#    #+#             */
/*   Updated: 2023/12/11 15:31:58 by justo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


//un buffer est necessaire pour pouvoir lire a repetition une certaine distance dans le fichier
#define BUFFER_SIZE 1024

//Jai besoin d'un efonction qui lit une ligne entiere :
// eller renvoie 1 lorsqu'on est arrivé à la fin d'une ligne, 0 lorsque c'est la fin du fichier, -1 en cas d'erreur
int read_line(fd, char *buffer, );


//fction qui permet de compter
int    counting(void)
{
    static int  count;
    
    count = 0;
    write(1, (count+48), 1);
    count++;
}

// Cette fonction va pouvoir lancer les autres fonction
char    *get_next_line(int fd)
{
    
}

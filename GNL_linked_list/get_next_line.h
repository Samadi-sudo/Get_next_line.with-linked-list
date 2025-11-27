/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <abantari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:09:19 by abantari          #+#    #+#             */
/*   Updated: 2025/11/26 21:09:19 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    char    *data;
	ssize_t	len;
    struct s_list *next;
}   t_list;

//next_line
char    *get_next_line(int fd);
//utils
int     ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
ssize_t  find_nl(const char *s);
t_list    *lstaddback(t_list **head, t_list **tail, const char *s, ssize_t state);
void    lst_clear(t_list *head);

#endif

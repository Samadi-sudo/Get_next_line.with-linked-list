/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:12:09 by abantari          #+#    #+#             */
/*   Updated: 2025/11/21 15:12:13 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	size_t			len;
	char			*data;
}					t_list;

//get_next_line
char	*get_next_line(int fd);

// utils
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, size_t start, size_t len);
t_list	*new_lst(char *buff, size_t state);
void	add_lst_back(t_list **head, t_list *new);
size_t	check_new_line(t_list *node);
size_t	ft_len_lst(char *rest, t_list *head, t_list *create, size_t check);

//get_next_line_bonus

//utils_bonus

#endif

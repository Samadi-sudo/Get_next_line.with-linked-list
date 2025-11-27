/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:50:50 by abantari          #+#    #+#             */
/*   Updated: 2025/11/27 14:50:51 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*data;
	ssize_t			len;
	struct s_list	*next;
}					t_list;

// next_line
char				*get_next_line(int fd);
// utils
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
ssize_t				find_nl(const char *s);
t_list				*lstaddback(t_list **head, t_list **tail, const char *s,
						ssize_t state);
void				lst_clear(t_list *head);
// helper norminnete

inline static void	free_stash(char **stash)
{
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
}

#endif

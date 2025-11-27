/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:50:21 by abantari          #+#    #+#             */
/*   Updated: 2025/11/27 14:50:23 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	lst_str_ft(ssize_t index, char **stash, t_list *tail)
{
	if (index == -1)
		free_stash(stash);
	else
	{
		if ((size_t)(index + 1) < ft_strlen(tail->data))
		{
			if (*stash)
				free(*stash);
			*stash = ft_strdup(tail->data + index + 1);
		}
		else
			free_stash(stash);
	}
}

static char	*lst_str_f(ssize_t index, char *line, t_list *head, t_list *tail)
{
	t_list	*curr_list;
	size_t	i;
	size_t	j;

	i = 0;
	curr_list = head;
	while (curr_list != tail)
	{
		j = 0;
		while (curr_list->data[j])
			line[i++] = curr_list->data[j++];
		curr_list = curr_list->next;
	}
	j = 0;
	if (index == -1)
	{
		while (j < (size_t)tail->len)
			line[i++] = tail->data[j++];
	}
	else
	{
		while (j <= (size_t)index && j < (size_t)tail->len)
			line[i++] = tail->data[j++];
	}
	return (line[i] = '\0', line);
}

static char	*lst_str(ssize_t index, char **stash, t_list *head, t_list *tail)
{
	char	*line;
	t_list	*curr_lst;
	size_t	total;

	total = 0;
	curr_lst = head;
	while (curr_lst != tail)
	{
		total += curr_lst->len;
		curr_lst = curr_lst->next;
	}
	if (index == -1)
		total += tail->len;
	else
		total += (index + 1);
	if (total == 0)
		return (free_stash(stash), NULL);
	line = malloc(total + 1);
	if (!line)
		return (free_stash(stash), NULL);
	lst_str_f(index, line, head, tail);
	lst_str_ft(index, stash, tail);
	return (line);
}

static char	*read_loop(int fd, t_list **head, t_list **tail, char **stash)
{
	char	*buff;
	ssize_t	state;
	ssize_t	index;

	state = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	index = find_nl((*tail)->data);
	while (index == -1 && state > 0)
	{
		state = read(fd, buff, BUFFER_SIZE);
		if (state <= 0)
			break ;
		buff[state] = '\0';
		if (!lstaddback(head, tail, buff, state))
		{
			free(buff);
			return (NULL);
		}
		index = find_nl((*tail)->data);
	}
	if (state < 0)
		return (free(buff), free_stash(stash), NULL);
	return (free(buff), lst_str(index, stash, *head, *tail));
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	t_list		*head;
	t_list		*tail;
	char		*line;

	head = NULL;
	tail = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (stash[fd])
	{
		if (!lstaddback(&head, &tail, stash[fd], ft_strlen(stash[fd])))
			return (free(stash[fd]), stash[fd] = NULL, NULL);
		free(stash[fd]);
		stash[fd] = NULL;
	}
	else
	{
		if (!lstaddback(&head, &tail, "", 0))
			return (NULL);
	}
	line = read_loop(fd, &head, &tail, &stash[fd]);
	lst_clear(head);
	return (line);
}

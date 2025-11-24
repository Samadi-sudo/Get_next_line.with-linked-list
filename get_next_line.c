/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:11:51 by abantari          #+#    #+#             */
/*   Updated: 2025/11/21 15:11:53 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	free_lst(t_list *head)
{
	t_list	*next;

	while (head)
	{
		next = head->next;
		free(head->data);
		free(head);
		head = next;
	}
}

static void	remplir(char *str, t_list *head, char *rest, t_list *create,
		size_t check)
{
	size_t	i;
	size_t	j;
	t_list	*curr;

	i = 0;
	curr = head;
	if (rest)
		while (rest[i])
			str[i] = rest[i], i++;
	while (curr)
	{
		j = 0;
		while (j < curr->len)
			str[i++] = curr->data[j++];
		curr = curr->next;
	}
	j = 0;
	while (j < check)
		str[i++] = create->data[j++];
	str[i] = '\0';
	free_lst(head);
}

static char	*lst_to_str(char *rest, t_list *head, t_list *create, size_t check)
{
	char	*str;
	size_t	len;

	len = ft_len_lst(rest, head, create, check);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	remplir(str, head, rest, create, check);
	return (str);
}

static char	*do_the_work(char **rest, char *buff, size_t state, int fd)
{
	char	*str;
	t_list	*create;
	t_list	*head;
	size_t	check;
	size_t	remain_len;

	head = NULL;
	create = new_lst(buff, state);
	check = check_new_line(create);
	while (!check)
	{
		add_lst_back(&head, create);
		state = read(fd, buff, BUFFER_SIZE);
		if (state <= 0)
			return (str = lst_to_str(*rest, head, create, 0), free(create),
				*rest = NULL, str);
		create = new_lst(buff, state);
		check = check_new_line(create);
	}
	str = lst_to_str(*rest, head, create, check);
	free(*rest);
	remain_len = create->len - check;
	if (remain_len > 0)
	{
		*rest = malloc(remain_len + 1);
		if (*rest)
		{
			for (size_t i = 0; i < remain_len; i++)
				(*rest)[i] = create->data[check + i];
			(*rest)[remain_len] = '\0';
		}
	}
	else
		*rest = NULL;
	free(create->data);
	free(create);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buff;
	char		*str;
	size_t		state;
	size_t		i;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (rest)
	{
		i = 0;
		while (rest[i] && rest[i] != '\n')
			i++;
		if (rest[i] == '\n')
		{
			str = malloc(i + 2);
			if (!str)
				return (free(buff), NULL);
			for (size_t j = 0; j <= i; j++)
				str[j] = rest[j];
			str[i + 1] = '\0';
			tmp = NULL;
			for (size_t j = i + 1; j < ft_strlen(rest); j++)
				tmp = realloc(tmp, j - i), tmp[j - i - 1] = rest[j];
			free(rest);
			rest = tmp;
			return (free(buff), str);
		}
	}
	state = read(fd, buff, BUFFER_SIZE);
	if (state <= 0)
		return (free(buff), NULL);
	str = do_the_work(&rest, buff, state, fd);
	return (free(buff), str);
}
/*

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // already includes newline
		free(line);
	}

	close(fd);
	return (0);
}*/

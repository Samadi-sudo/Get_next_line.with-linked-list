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



static 

static void remplir(char *str, t_list *head, char *rest, t_list *create)
{
	size_t	j;
	t_lst	*curr_lst;

	i = 0;
	curr_lst = head;
	while (curr_lst)
	{
		j = 0;
		while(head->data[j])
		{
			*str = head->data[j]
			j++;
		}
		curr_lst = curr_lst->next;
	}
	j = create->len - check;
	while (rest[j])
	{
		*str = rest[j]
		str++;
		j++;
	}
	*str = '\0';
}
	
static	char *lst_to_str(char *rest, t_list *head, t_list *create, size_t check)
{
	size_t	len_lst;
	size_t	len_rest;
	char	*str;

	len_lst = ft_len_lst(rest, head, create, check);
	str = malloc(len_lst + 1);
	if (!str)
		return (NULL);
	remplir(str, head,  rest, create);
}

char	*do_the_work(char *rest, char *buff, size_t state)
{
	char	*str;
	t_list	*create;
	t_list	*head;
	size_t	check;

	head = NULL;
	create = new_lst(buff, state);
	check  = check_new_line(create);
	while (!check)
	{
		add_lst_back(&head, new);
		create = new_lst(buff, state);
		check  = check_new_line(create);
	}
	
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char	*buff;
	size_t	state;

	if (!buff)
		buff = malloc(BUFFER_SIZE + 1);
	if (!buff && BUFFER_SIZE <= 0)
		return (NULL);
	state = read(fd, buff, BUFFER_SIZE);
	if(state <= 0)
		return (free(buff), NULL);
	else
	{
		do_the_work(rest, buff, state);
	}
	return(free(buff), free(rest), NULL)
}

int	main(void)
{
	int		fd;
	char	*c;

	fd = open("text.txt", O_RDONLY);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
}

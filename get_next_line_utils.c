/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:12:26 by abantari          #+#    #+#             */
/*   Updated: 2025/11/21 15:12:27 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *cursor, ssize_t state)
{
	t_list	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = malloc(state + 1);
	if (!(new->data))
	{
		free(new);
		return (NULL);
	}
	while (i < state)
	{
		new->data[i] = cursor[i];
		i++;
	}
	new->data[state] = '\0';
	new->len = state;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur_lst;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cur_lst = *lst;
	while (cur_lst->next)
		cur_lst = cur_lst->next;
	cur_lst->next = new;
}

size_t	size_of_list(t_list *head, t_list *create)
{
	size_t	len;
	size_t	i;
	size_t	check;
	t_list	curr_list;

	len = 0;
	curr_list = head;
	while(curr_list)
	{
		len += curr_list->len;
		curr_list = curr_list->next;
	}
	check = check_next_line(create);
	if (check)
		len += check;
	return (len);
}

size_t	check_next_line(t_list *node);
{
	size_t	i;
	int	flag;

	i = 0;
	flag = 0;
	while(node->data[i])
	{
		if (node->data[i] == '\n')
		{
			flag = 1;
			break;
		}
		i++;
	}
	return(flag * i);
}

char	*from_list_to_str(t_list *head, t_list *create, char * cursor)
{
	char	*str;
	char	*rest;
	size_t	i;
	t_list	current_lst;

	str = malloc(size_of_list(head,create) + 1);
	if (!str)
		return (NULL);
	while(current_list)
	{
		i = 0;
		while (current_list->data[i])
		{
			*str = current_list->data[i];
			str++;
			i++;
		}
		current_list = current->next;
	}
	
	return (str);
}








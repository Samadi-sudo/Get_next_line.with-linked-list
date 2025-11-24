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

size_t	ft_strlen(char *str)
{
	size_t	len;
	while (str[len])
		len++;
	return (len);
}

t_list	*new_lst(char *buff, size_t state)
{
	t_list	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = malloc(state + 1);
	if (!new->data)
		return (free(new), NULL);
	while (i < state)
	{
		new->data[i] = buff[i];
		i++;
	}
	new->data[state] = '\0';
	new->len = state;
	new->next = NULL;
	return (new);
}

void	add_lst_back(t_list **head, t_list *new)
{
	t_list *current;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

size_t	check_new_line(t_list *new)
{
	size_t	i;
	int	flag;

	i = 0;
	flag = 0;
	while (new->data[i])
	{
		if (new->data[i] == '\n')
		{
			flag = 1;
			break;
		}
		i++;
	}
	return (flag * i); 
}

size_t	ft_len_lst(char *rest, t_list *head, t_list *create,size_t check)
{
	size_t	len;
	t_list *cur_lst;

	len = 0;
	if (!head)
		return (0);
	if (rest != NULL)
		len += ft_strlen(rest);
	while (cur_lst)
		len += cur_lst->len;
	if (check)
		len += check;
	return (len);
}


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



char	*get_next_line(int fd)
{
	static char	*cursor;
	size_t	i;
	t_list	*create;
	t_list	*head;

	i = 0;
	head = NULL;
	if (!cursor)
		cursor = malloc(BUFFER_SIZE + 1);
	if (!cursor && BUFFER_SIZE <= 0)
		return (NULL);
	state = read(fd, cursor, BUFFER_SIZE);
	if (state <= 0)
		return (free(cursor), NULL);
	create = ft_lstnew(cusor, state);
	if (!head && create != NULL)
		head = create;
	else
		
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

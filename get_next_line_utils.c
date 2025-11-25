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

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	size_t			i;
	char			*first;

	if (!s)
		return (NULL);
	i = 0;
	first = (char *)s;
	uc = (unsigned char)c;
	while (first[i] && first[i] != uc)
		i++;
	if (first[i] == uc)
		return (&first[i]);
	return (NULL);
}

char	*ft_strjoin(char *buff, char *saved)
{
	size_t	i;
	char *str;

	if (!buff || !saved)
		return (NULL);
	str = malloc(ft_strlen(buff); + ft_strlen(saved); + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i])
	{
		str[i] = buff[i]; 
		i++;
	}
	while (saved)
	{
		str[i] = *saved;
		i++;
		saved++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

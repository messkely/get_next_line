/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:30:56 by messkely          #+#    #+#             */
/*   Updated: 2023/12/31 17:52:19 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	if (s[i] == '\0')
		return ((char *)&s[i]);
	while (*s != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char *ft_clear(char *buff)
{
    free(buff);
    return (NULL);
}

char	*ft_line(char *left_str)
{
	int		i;
	char	*ptr_line;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	ptr_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!ptr_line)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		ptr_line[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		ptr_line[i] = left_str[i];
		i++;
	}
	ptr_line[i] = '\0';
	return (ptr_line);
}

char	*ft_new_buff(char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
		return (ft_clear(buff));
	str = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 2));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		str[j++] = buff[i++];
	str[j] = '\0';
	free(buff);
	return (str);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *ptr;
	int i = 0;
	int j = 0;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
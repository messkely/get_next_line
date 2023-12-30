/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:30:56 by messkely          #+#    #+#             */
/*   Updated: 2023/12/30 13:14:22 by messkely         ###   ########.fr       */
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
	if (!s)
		return (ft_clear(s));
	if (*s == '\0')
		return ((char *)s);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			s++;
			return ((char *)s);
		}
		s++;
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
	ptr_line = malloc(sizeof(char) * (i + 1));
	if (!ptr_line)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
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
	int len;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
		return (ft_clear(buff));
	len = ft_strlen(buff) - i;
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		str[j++] = buff[i++];
	// str = ft_strchr(buff,'\n');
	free(buff);
	return (str);
}

static char *ft_strcat(char *dst, const char *src)
{
    char *org_dst;

    org_dst = dst;
	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (org_dst);
}

static char *ft_strcpy(char *dst, const char *src)
{
    char *org_dst;

    org_dst = dst;
    while (*src)
        *dst++ = *src++;
    *dst = '\0';
    return org_dst;
}


char *ft_strjoin(char *s1, char *s2)
{
	char *ptr;

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
	ptr = ft_strcpy(ptr, s1);
	ptr = ft_strcat(ptr, s2);
	free(s1);
	return (ptr);
}
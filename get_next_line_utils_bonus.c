/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:46:54 by messkely          #+#    #+#             */
/*   Updated: 2024/01/04 11:55:06 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_clear(char *str)
{
	free(str);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			i++;
			return ((char *)&s[i]);
		}
		i++;
	}
	return (0);
}

void	fill_str(char *res, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
}

char	*ft_strjoin(char *content, char *buff)
{
	char	*str;

	if (!content)
	{
		content = (char *)malloc(1 * sizeof(char));
		content[0] = '\0';
	}
	if (!content || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(content) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	fill_str(str, content, buff);
	free(content);
	return (str);
}

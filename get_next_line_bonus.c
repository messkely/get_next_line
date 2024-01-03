/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:46:15 by messkely          #+#    #+#             */
/*   Updated: 2024/01/03 10:46:35 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *content)
{
	int		i;
	char	*str;

	i = 0;
	if (!content[i])
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		str[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
	{
		str[i] = content[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*new_str(char *content)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
		return (ft_clear(content));
	str = malloc(sizeof(char) * (ft_strlen(content) - i));
	if (!str)
		return (ft_clear(str));
	i++;
	j = 0;
	while (content[i])
		str[j++] = content[i++];
	str[j] = '\0';
	free(content);
	return (str);
}

static char	*read_str(int fd, char *content, char *buff)
{
	int		rd_byt;

	rd_byt = 1;
	while (!ft_strchr(content, '\n') && rd_byt)
	{
		rd_byt = read(fd, buff, BUFFER_SIZE);
		if (rd_byt == -1)
			return (ft_clear(buff));
		buff[rd_byt] = '\0';
		content = ft_strjoin(content, buff);
	}
	free(buff);
	return (content);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*static_buff[4096];

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > 4096)
	{
		static_buff[fd] = ft_clear(static_buff[fd]);
		buff = ft_clear(buff);
		return (NULL);
	}
    if (!buff)
        return (NULL);
	static_buff[fd] = read_str(fd, static_buff[fd], buff);
	if (!static_buff[fd])
		return (ft_clear(static_buff[fd]));
	line = ft_get_line(static_buff[fd]);
	static_buff[fd] = new_str(static_buff[fd]);
	return (line);
}
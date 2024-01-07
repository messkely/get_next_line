/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:29:37 by messkely          #+#    #+#             */
/*   Updated: 2024/01/05 18:33:15 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*static_buff;

	buff = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		static_buff = ft_clear(static_buff);
		buff = ft_clear(buff);
		return (NULL);
	}
	static_buff = read_str(fd, static_buff, buff);
	if (!static_buff)
		return (ft_clear(static_buff));
	line = ft_get_line(static_buff);
	static_buff = new_str(static_buff);
	return (line);
}

// int main()
// {
// 	int fd = open("test.txt",O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("%s",line);
// 	close(fd);
// }
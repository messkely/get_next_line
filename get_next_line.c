/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:29:37 by messkely          #+#    #+#             */
/*   Updated: 2023/12/30 13:16:21 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_to_left_str(int fd, char *left_str)
{
    char *buff;
    int byt_to_read;

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
    byt_to_read = 1;
    while (!ft_strchr(left_str, '\n') && byt_to_read != 0)
    {
        byt_to_read = read(fd, buff, BUFFER_SIZE);
        if (byt_to_read == -1)
            return (ft_clear(buff));
        buff[byt_to_read] = '\0';
        left_str = ft_strjoin(left_str, buff);
    }
    free(buff);
    return (left_str);
}

char *get_next_line(int fd)
{
    char *line;
    static char *left_str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    left_str = ft_read_to_left_str(fd, left_str);
    if (!left_str)
        return (NULL);
    line = ft_line(left_str);
    left_str = strdup(ft_strchr(left_str, '\n'));
    free(left_str);
    // left_str = ft_new_buff(left_str);
    return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		// line = get_next_line(fd3);
// 		// printf("line [%02d]: %s", i, line);
// 		// free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
// int main()
// {
//     printf("%s",strdup(ft_strchr("skdj kkfdl \n eirrpe rit\njfdoor dijf\njfjffjjf\njgfj\n",'\n')));
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:29:37 by messkely          #+#    #+#             */
/*   Updated: 2023/12/31 17:50:44 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *buff;
    int byt_readed;
    char *line;
    static char *left_str;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        return (ft_clear(left_str));
    }
    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
    byt_readed = 1;
    while (byt_readed > 0)
    {
        byt_readed = read(fd, buff, BUFFER_SIZE);
        if (byt_readed == -1)
            return (ft_clear(buff));
        buff[byt_readed] = '\0';
        left_str = ft_strjoin(left_str, buff);
    }
    free(buff);
    if (!left_str)
        return (NULL);
        // return (ft_clear(left_str));
    line = ft_line(left_str);
    left_str = ft_new_buff(left_str);
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
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
//     // system("leaks a.out");
// 	return (0);
// }

// int main()
// {
//     char *line;
//     int fd,i;

//     fd = open("test.txt", O_RDONLY);
    
//     i = 1;
//     while (i < 5)
//     {
//         line = get_next_line(fd);
//         printf("line [%02d]: %s", i, line);
//         free(line);
//         i++;
//     }
//     close(fd);
//     //system("leaks a.out");
//     return (0);
// }

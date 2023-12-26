#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *buff;
    int count_n;
    int count_byt;
    static char *left_str;
    int *pos;
    int i;
    int j;

    count_n = count_n(char *buff);
    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
    while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
    {
        count_byt = read(fd,buff, BUFFER_SIZE);
        if (count_byt == -1)
        {
            free(buff);
            return (NULL);
        }
    }
    buff[count_byt] = '\0';
    pos = find_position_n(buff);
    i = 0;
    j = 0;
    while (pos[i])
    {
        while (buff[j])
        {
            if (pos[i] == j)
            {
                while (e < j)
                {
                    f
                }
            }
            j++;
        }
    }
    free(pos);
}
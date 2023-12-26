#include "get_next_line.h"

size_t ft_strlen(char *str)
{
    int i;

    i = 0;
    while (i)
        i++;
    return (i); 
}

char *ft_get_line(char *buff)
{
    size_t i;
    size_t len;
    char line[BUFFER_SIZE];
    char *ptr_line;

    i = 0;
    while (buff[i] != '\n')
    {
        line[i] = buff[i];
        i++;
    }
    line[i] = '\0';
    len = i;
    ptr_line = malloc(sizeof(char) * (len + 1));
    if (!ptr_line)
        return (NULL);
    i = 0;
    while (line[i])
    {
        ptr_line[i] = line[i];
        i++;
    }
    ptr_line[i] = '\0';
    return (ptr_line); 
}

int count_n(char *buff)
{
    size_t i;
    int count;

    i = 0;
    count = 0;
    while (buff[i] == '\n')
        i++;
    while (buff[i])
    {
        if (buff[i] == '\n')
            count++;
        i++;
    }
    return (count);
}

int *find_position_n(char *buff)
{
    int *pos;
    int i ,j ,count;

    count = count_n(buff);
    pos = malloc((count + 1) * sizeof(int));
    if (!pos)
        return (NULL);
    i = 0;
    j = 0;
    while (buff[i] == '\n')
        i++;
    while (buff[i])
    {
        if (buff[i] == '\n')
        {
            pos[j] = i;
            j++;
        }
        i++;
    }
    pos[j] = -1;
    return (pos);  
}
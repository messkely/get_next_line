#include "get_next_line.h"

char *read_file(int fd)
{
    char *buff;
    int i;
    int rd_byt;

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
    rd_byt = read(fd, buff, BUFFER_SIZE);

    buff[rd_byt] = '\0';
    return (buff);
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    // int i = 0;
    // while ()
    // {
        printf("%s\n",read_file(fd));
    //     // i++;
    // }
}
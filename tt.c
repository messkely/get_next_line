#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int main()
{
    char *s1 = "";
    char *s2 = "world";
    char *res = ft_strjoin(s1, s2);
    printf("%s",res);
    free(res);
}
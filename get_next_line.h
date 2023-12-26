#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

size_t ft_strlen(char *str);
char *ft_get_line(char *buff);
int count_n(char *buff);
int *find_position_n(char *buff);
#endif
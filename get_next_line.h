/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:30:14 by messkely          #+#    #+#             */
/*   Updated: 2023/12/30 18:41:25 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

size_t ft_strlen(char *str);
char *get_next_line(int fd);
char *ft_line(char *buff);
char *ft_clear(char *buff);
char *ft_new_buff(char *left_str);
char *ft_strjoin(char *s1, char *s2);
// char *ft_read_to_left_str(int fd, char *left_str);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
#endif
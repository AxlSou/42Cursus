/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:10:28 by asoubiel          #+#    #+#             */
/*   Updated: 2024/08/17 20:38:00 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *get_next_line(int fd);
size_t ft_strlen_gnl(const char *str);
char *ft_substr_gnl(char const *s, unsigned int start, size_t len);
char *ft_strjoin_gnl(char const *s1, char const *s2);
int ft_strchr_gnl(char *str, int c);
char *ft_read_file(int fd, char *buf, char *str);
char *get_new_line(char *str);
void *ft_free_gnl(char *ptr);

#endif

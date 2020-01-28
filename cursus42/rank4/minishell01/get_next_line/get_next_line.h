/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:19:09 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/26 17:04:39 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif

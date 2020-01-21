/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:02:30 by acarvaja          #+#    #+#             */
/*   Updated: 2020/01/17 01:30:54 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libasm.h"

int main(void)
{
    int fd;
    int bytes_read;
    char *buf = malloc(sizeof(char) * 2);

    fd = open("Makefile", O_RDONLY);
    while ((bytes_read = ft_read(fd, buf, 1)) > 0)
        printf("%s", buf);
    close(fd);
    return (0);
}
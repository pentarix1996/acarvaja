/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tester_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:41:21 by mchardin          #+#    #+#             */
/*   Updated: 2019/11/14 20:49:13 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int             fd;
	int             i;
	int             j;
	char    *line = 0;
	char    *lineadress[66];
	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/alphabet", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("Not Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
	j = 1;

	printf("\n==========================================\n");
	printf("========= TEST 2 : Empty Lines ===========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/empty_lines", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 9)
		printf("\nRight number of lines\n");
	else if (j != 9)
		printf("Not Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("======== TEST 3 : The Empty File =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/empty_file", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 1)
		printf("\nRight number of lines\n");
	else if (j != 1)
		printf("Not Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 4 : One New Line ==========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/1_newline", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 2)
		printf("\nRight number of lines\n");
	else if (j != 2)
		printf("Not Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 5 : Four New Lines ========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/4_newlines", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 5)
		printf("\nRight number of lines\n");
	else if (j != 5)
		printf("Not Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 6 : Wrong Input ===========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/alphabet", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	if (get_next_line(180, &line) == -1)
		printf("Well Done, you return -1 if no FD\n");
	else
		printf("Not Good, you don't return -1 if no FD\n");
	if (get_next_line(fd, 0) == -1)
		printf("Well Done, you return -1 if no line\n");
	else
		printf("Not Good, you don't return -1 if no line\n");
	close(fd);
	j = 1;
	printf("\n==========================================\n");
	printf("============== TEST 7 : 42 ===============\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/41_char", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (!(fd = open("files/42_char", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{

		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (!(fd = open("files/43_char", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 1)
		printf("\nRight number of lines\n");
	else if (j != 1)
		printf("Not Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("============= TEST 8 : Marge =============\n");
	printf("==========================================\n\n");

	int fd2;

	if (!(fd = open("files/mix_marge1", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	if (!(fd2 = open("files/mix_marge2", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while (j < 8)
	{
		if ((i = get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	while (j < 13)
	{
		if ((i = get_next_line(fd2, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	while (j < 23)
	{
		if ((i = get_next_line(fd2, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	j++;
	while (j < 25)
	{
		if ((i = get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 25)
		printf("\nRight number of lines\n");
	else if (j != 25)
		printf("Not Good - Wrong Number Of Lines\n");
	return (0);
}

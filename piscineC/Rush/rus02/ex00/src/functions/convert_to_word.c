/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:09:06 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/23 19:59:29 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../lib/number.h"
#include <stdio.h>

char	**ft_split(char *str, char *charset, int i, int j);
char	**separate_order(char **table);
char	*reserve_memorynbr(char *next);
char	*reserve_memorynbrstr(char *next, char *nbrstr);
char	*set_nbr(char *nbr, t_nbrtree binary);
char	*set_nbrstr(char *nbrstr, t_nbrtree binary);
int		*ft_strlen(char *str);
void	print_number(char *arg, t_nbrtree *my_tree, int i, int k);
t_nbrtree	*structure_tree(t_nbrtree *my_tree, int i);

void	convert_to_word(char *arg, char *dicct, int j, int k)
{
	char		**table;
	int			i;
	char		*nbr;
	char		*nbrstr;
	t_nbrtree	*my_tree;

	i = 0;
	table = ft_split(dicct, "\n", i, j);
	table = separate_order(table);
	while (table[i] != '\0')
		i++;
	my_tree = malloc(sizeof(t_nbrtree) * i);
	i = -1;
	while (table[++i + 2] != '\0')
	{
		nbr = reserve_memorynbr(table[i]);
		if (*table[i] != ' ')
			my_tree[i].nbr = set_nbr(nbr, my_tree[i]);
		nbrstr = reserve_memorynbrstr(table[i], nbrstr);
		if (*table[i] != ' ')
			my_tree[i].nbrstr = set_nbrstr(nbrstr, my_tree[i]);
	}
	my_tree = structure_tree(my_tree, i);
	if (*arg == '0')
		printf("%s ", (*my_tree).nbrstr);
	print_number(arg, my_tree, j, k);
}

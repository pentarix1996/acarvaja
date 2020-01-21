# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/26 16:53:11 by acarvaja          #+#    #+#              #
#    Updated: 2019/12/26 16:53:13 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Werror -Wextra union.c -o union
echo "# Expected result (next line) Your result #"
echo "---"
echo "zpadintoqefwjy$"
./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
echo "---"
echo "df6vewg4thras$"
./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
echo "---"
echo "rienct phas$"
./union "rien" "cette phrase ne cache rien" | cat -e
echo "---"
echo "$"
./union | cat -e
echo "---"
echo "$"
./union "rien" | cat -e

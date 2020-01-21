# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/26 16:46:32 by acarvaja          #+#    #+#              #
#    Updated: 2019/12/26 16:58:02 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Werror -Wextra inter.c -o inter
echo "# Expected result (next line) Your result #"
echo "---"
echo "padinto$"
./inter zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
echo "---"
echo "df6ewg4$"
./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
echo "---"
echo "rien$"
./inter "rien" "cette phrase ne cache rien" | cat -e
echo "---"
echo "$"
./inter | cat -e
echo "---"
echo "$"
./inter "rien" | cat -e

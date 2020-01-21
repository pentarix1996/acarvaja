# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/26 18:27:51 by acarvaja          #+#    #+#              #
#    Updated: 2019/12/26 18:27:52 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Werror -Wextra get_next_line.c main.c -o get_next_line
./get_next_line < get_next_line.c > yours_.res
cat -e yours_.res > yours.res
cat -e < get_next_line.c > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res get_next_line

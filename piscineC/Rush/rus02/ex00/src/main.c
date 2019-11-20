/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:00:46 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 21:41:24 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_warning(char *str);
void	ft_error(char *str);
void	ft_error_no_exit(char *str);
void	ft_info(char *str);
char	*load_dictionary(char *lang);
void	ft_putstr(char *str);
int		ft_isnbr(char *str);
void	convert_to_word(char *arg, char *dicct, int j, int k);

int		main(int argc, char **argv)
{
	char	*dict;
	int		j;
	int		k;
	char	*number;

	j = 0;
	k = 0;
	dict = load_dictionary("en");
	if (argc < 2)
	{
		ft_error_no_exit("Necesitas intoducir 1 número\n");
		ft_info("Syntax: ./executable [?lang (en, gb)] [!number]\n");
	}
	if (argc < 3)
	{
		number = argv[1];
	}
	if (argc > 3)
		ft_error("Demasiados argumentos...\n");
	if (argc == 3)
	{
		number = argv[2];
		dict = load_dictionary(argv[1]);
	}
	if (!ft_isnbr(number))
		ft_error("El número que has introducido no es válido.\n");
	convert_to_word(argv[1], dict, j, k);
	return (0);
}

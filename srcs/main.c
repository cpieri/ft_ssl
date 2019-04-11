/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:05:16 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 19:31:12 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int ac, char **av)
{
	t_parse	parse;

	if (ac < 2)
		print_usage(1, NULL);
	parse = parsing(ac, av);
	print_lst(&(parse.lst_opts));
	// hashing(&parse);
	// clean_prog(&parse);
	return (0);
}

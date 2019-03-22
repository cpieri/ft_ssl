/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/22 14:41:58 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_parse			parsing(const int ac, char **av)
{
	t_parse			parse;
	int				now;

	now = 1;
	parse.hash_type = 0;
	parse.lst_opts = NULL;
	if (ft_strcmp("md5", av[now]) == 0)
	{
		parse.hash_type = e_md5;
		parse.fparse = hash_opts;
		parse.func = md5;
		parse.name = "MD5";
	}
	else if (ft_strcmp("sha256", av[now]) == 0)
	{
		parse.hash_type = e_sha256;
		parse.fparse = hash_opts;
		parse.func = sha256;
		parse.name = "SHA256";
	}
	else
		print_usage(2, av[1]);
	parse.lst_opts = parse.fparse(ac, av, NULL, now + 1);
	return (parse);
}

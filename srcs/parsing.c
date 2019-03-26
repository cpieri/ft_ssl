/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/26 16:08:53 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

t_parse			parsing(const int ac, char **av)
{
	t_parse			parse;
	int				now;

	now = 1;
	parse.hash_type = 0;
	parse.lst_opts = NULL;
	if (ft_strcmp("md5", av[now]) == 0)
		parse = (t_parse)SET_MD5;
	else if (ft_strcmp("sha256", av[now]) == 0)
		parse = (t_parse)SET_SHA256;
	else if (ft_strcmp("sha512", av[now]) == 0)
		parse = (t_parse)SET_SHA512;
	else
		print_usage(2, av[1]);
	parse.lst_opts = parse.fparse(ac, av, NULL, now + 1);
	return (parse);
}

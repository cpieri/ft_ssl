/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/30 09:00:08 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const t_parse		g_all_cmd[] =
{
	{"md5", "MD5", e_hash, md5, hash_opts, printing_hash, NULL},
	{"sha1", "SHA1", e_hash, sha1, hash_opts, printing_hash, NULL},
	{"sha256", "SHA256", e_hash, sha256, hash_opts, printing_hash, NULL},
	{"base64", "base64", e_cipher, base64, base64_opts, printing_base64, NULL},
	{"des", "des", e_cipher, des, symmetric_opts, NULL, NULL},
	{NULL, NULL, 0, NULL, NULL, NULL, NULL},
};

t_parse			parsing(const int ac, char **av)
{
	t_parse		parse;
	int			i;
	int			now;

	now = 1;
	i = 0;
	parse = (t_parse){NULL, NULL, 0, NULL, NULL, NULL, NULL};
	while (g_all_cmd[i].cmd != NULL)
	{
		if (ft_strcmp(g_all_cmd[i].cmd, av[now]) == 0)
		{
			parse = g_all_cmd[i];
			parse.lst_opts = parse.fparse(ac, av, NULL, now + 1);
			return (parse);
		}
		i++;
	}
	print_usage(2, av[1]);
	return (parse);
}

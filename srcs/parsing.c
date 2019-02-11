/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42->fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/11 17:39:05 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ssl_md5.h"

static t_opt	*parse_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	new = NULL;
	if (av[now][0] == '-' || ac < 3)
	{
		if (ac < 3 || ft_strcmp("-p", av[now]) == 0)
			new = new_opt(ARG_P, get_data(0));
		else if (ft_strcmp("-q", av[now]) == 0 || ft_strcmp("-r", av[now]))
			new = new_opt(ARG_Q, get_data(open_fd(av[now + 1])));
		else if (ft_strcmp("-s", av[now]) == 0)
			new = new_opt(ARG_S, av[now + 1]);
		add_to_end_lst(new, &opts);
	}
	now++;
	if (now < ac)
		parse_opts(ac, av, opts, now);
	return (opts);
}

t_parse			*parsing(const int ac, char **av)
{
	t_parse	*parse;
	int		now;

	now = 1;
	if (!(parse = (t_parse*)malloc(sizeof(t_parse) * 1)))
		return (NULL);
	if (ft_strcmp("md5", av[now]) == 0)
		parse->lst_opts = parse_opts(ac, av, parse->lst_opts, now + 1);
	else if (ft_strcmp("sha256", av[now]) == 0)
		parse->lst_opts = parse_opts(ac, av, parse->lst_opts, now + 1);
	else
		print_usage(2, av[1]);
	print_lst(&parse->lst_opts);
	return (parse);
}

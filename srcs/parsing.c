/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/06 15:16:39 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*	if (ac < 3 || ft_strcmp("-p", av[now]) == 0)
	new = new_opt(ARG_P, get_data(0, NULL));
	else if (ft_strcmp("-q", av[now]) == 0 || ft_strcmp("-r", av[now]) == 0)
	new = new_opt(ARG_Q, get_data(open_fd(av[now + 1]), av[now + 1]));
	else if (ft_strcmp("-s", av[now]) == 0)
	new = new_opt(ARG_S, get_string(av[now + 1]));
	else if (ft_strcmp("-s", av[now - 1]) != 0)
	new = new_opt(0, get_data(open_fd(av[now]), av[now]));*/

static t_opt	*check_flags(char **av, int now)
{
	t_opt		*new;
	t_flags		flags;
	char		*av_now;
	size_t		i;
	size_t		len;

	av_now = av[now];
	new = NULL;
	len = ft_strlen(av_now);
	i = 1;
	if (av_now[0] == '-')
	{
		while (i < len)
		{
			if (av_now[i] == 's')
			{
				if (i < len - 1)
					new = new_opt(flags, get_string(&av_now[i + 1]));
				else
					new = new_opt(flags, get_string(av[now + 1]));
				break ;
			}
			else if (av_now[i] == 'p')
			{
				new = new_opt(flags, get_data(0, NULL));
				break ;
			}
			else if (av_now[i] == 'q')
			{
				flags.r = 0;
				flags.q = 1;
			}
			else if (av_now[i] == 'r' && flags.q == 0)
				flags.r = 1;
			i++;
		}
		if (new == NULL)
			new = new_opt(flags, get_data(open_fd(av[now + 1]), av[now + 1]));
		return (new);
	}
	if (ft_strchr(av[now - 1], '-') == NULL)
	{
		flags = (t_flags){};
		new = new_opt(flags, get_data(open_fd(av_now), av_now));
	}
	return (new);
}

static t_opt	*parse_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	new = check_flags(av, now);
	add_to_end_lst(new, &opts);
	now++;
	if (now < ac)
		parse_opts(ac, av, opts, now);
	return (opts);
}

t_parse			parsing(const int ac, char **av)
{
	t_parse	parse;
	int		now;

	now = 1;
	parse.hash_type = 0;
	if (ft_strcmp("md5", av[now]) == 0)
		parse.hash_type = MD5;
	else if (ft_strcmp("sha256", av[now]) == 0)
		parse.hash_type = SHA256;
	else
		print_usage(2, av[1]);
	parse.lst_opts = parse_opts(ac, av, parse.lst_opts, now + 1);
	print_lst(&parse.lst_opts);
	return (parse);
}

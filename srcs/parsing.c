/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/20 19:52:02 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_opt	*check_flags(size_t len, t_flags *flags, char **av, int now)
{
	t_opt	*new;
	size_t	i;

	new = NULL;
	i = 0;
	while (++i < len)
	{
		if (new != NULL)
			break ;
		if (av[now][i] == 's')
		{
			flags->s = 1;
			if (i < (len - 1))
				new = new_opt(*flags, get_string(&av[now][i + 1]));
			else
				new = new_opt(*flags, get_string(av[now + 1]));
		}
		else if (av[now][i] == 'p')
			new = new_opt((t_flags){.p = 1}, get_data(0, NULL));
		else if (av[now][i] == 'q')
			*flags = (t_flags){0, .q = 1, 0, 0};
		else if (av[now][i] == 'r' && flags->q == 0)
			flags->r = 1;
	}
	return (new);
}

static t_opt	*get_args(char **av, int now)
{
	t_opt		*new;
	t_flags		flags;
	char		*tmp;
	size_t		len;

	tmp = NULL;
	new = NULL;
	flags = (t_flags){0, 0, 0, 0};
	if (av[now][0] == '-')
	{
		len = ft_strlen(av[now]);
		new = check_flags(len, &flags, av, now);
		if (new == NULL && av[now + 1] == NULL)
			new = new_opt(flags, get_data(0, NULL));
		else if (new == NULL && av[now + 1][0] != '-')
			new = new_opt(flags, get_data(open_fd(av[now + 1]), av[now + 1]));
		return (new);
	}
	else if (ft_strchr(av[now - 1], '-') == NULL
			|| (av[now - 1][0] == '-' && (ft_strchr(av[now - 1], 'p') != NULL
					|| ((tmp = ft_strchr(av[now - 1], 's')) && *(tmp + 1)))))
		new = new_opt(flags, get_data(open_fd(av[now]), av[now]));
	return (new);
}

static t_opt	*parse_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	if (ac < 3)
		new = new_opt((t_flags){0, 0, 0, 0}, get_data(0, NULL));
	else
		new = get_args(av, now);
	add_to_end_lst(new, &opts);
	now++;
	if (now < ac)
		opts = parse_opts(ac, av, opts, now);
	return (opts);
}

t_parse			parsing(const int ac, char **av)
{
	t_parse	parse;
	int		now;

	now = 1;
	parse.hash_type = 0;
	parse.lst_opts = NULL;
	if (ft_strcmp("md5", av[now]) == 0)
		parse.hash_type = MD5;
	else if (ft_strcmp("sha256", av[now]) == 0)
		parse.hash_type = SHA256;
	else
		print_usage(2, av[1]);
	parse.lst_opts = parse_opts(ac, av, NULL, now + 1);
	return (parse);
}

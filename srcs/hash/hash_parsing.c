/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:00:59 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/07 09:58:41 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_opt	*check_ha_flags(size_t len, t_flags *flags, char **av, int now)
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

static t_opt	*get_hash_args(char **av, int now)
{
	t_opt		*new;
	t_flags		flags;
	char		*tmp;
	size_t		len;

	tmp = NULL;
	new = NULL;
	flags = (t_flags){0, 0, 0, 0, 0, 0};
	if (av[now][0] == '-')
	{
		len = ft_strlen(av[now]);
		new = check_ha_flags(len, &flags, av, now);
		if (new == NULL && av[now + 1] == NULL)
			new = new_opt(flags, get_data(0, NULL));
		else if (new == NULL && av[now + 1][0] != '-' && av[now][1] != 'p')
			new = new_opt(flags, get_file(open_fd(av[now + 1]), av[now + 1]));
		return (new);
	}
	else if (ft_strchr(av[now - 1], '-') == NULL
			|| (av[now - 1][0] == '-' && (ft_strchr(av[now - 1], 'p') != NULL
					|| ((tmp = ft_strchr(av[now - 1], 's')) && *(tmp + 1)))))
		new = new_opt(flags, get_file(open_fd(av[now]), av[now]));
	return (new);
}

t_opt			*hash_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	if (ac < 3)
		new = new_opt((t_flags){0, 0, 0, 0, 0, 0}, get_data(0, NULL));
	else
		new = get_hash_args(av, now);
	add_to_end_lst(new, &opts);
	now++;
	if (now < ac)
		opts = hash_opts(ac, av, opts, now);
	return (opts);
}

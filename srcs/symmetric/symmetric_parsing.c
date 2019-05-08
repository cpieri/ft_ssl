/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:04:37 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/08 11:00:53 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "symmetric/symmetric.h"
#include <stdio.h>
#include <unistd.h>

static const t_sym_opt	g_sym_opt[] =
{
	{'a', e_sym_opt_a, get_sym_opt_a},
	{'d', e_sym_opt_d, get_sym_opt_d},
	{'e', e_sym_opt_e, get_sym_opt_e},
	{'i', e_sym_opt_i, get_sym_opt_i},
	{'o', e_sym_opt_o, get_sym_opt_o},
	{'k', e_sym_opt_k, get_sym_opt_k},
	{'s', e_sym_opt_s, get_sym_opt_s},
	{'p', e_sym_opt_p, get_sym_opt_p},
	{'v', e_sym_opt_v, get_sym_opt_v},
	{0, 0, NULL}
};

static void		get_sym_opt(char **av, int *now, t_opt *opt, t_sym_key **k)
{
	size_t		len_now;
	size_t		i;
	size_t		y;

	i = 0;
	len_now = ft_strlen(av[*now]);
	while (++i < len_now)
	{
		y = 0;
		while (g_sym_opt[y].opt != 0)
		{
			if (g_sym_opt[y].opt == av[*now][i])
				if (g_sym_opt[y].sym_opt_fun != NULL)
					g_sym_opt[y].sym_opt_fun(av, now, opt, k);
			y++;
		}
	}
}

static t_opt	*get_sym_args(const int ac, char **av, int now)
{
	t_opt		opt;
	t_sym_key	*k;

	(void)av;
	k = NULL;
	opt = (t_opt){NULL, {0, 0, 0, 0, 0, 0}, NULL};
	while (now < ac)
	{
		if (av[now][0] == '-')
			get_sym_opt(av, &now, &opt, &k);
		now++;
	}
	ft_membits(&(opt.flags.sym_flags), 0, sizeof(uint64_t));
	// if (k == NULL)
	// 	k = new_key(get_pass("enter your password: "), 0, 0, 0);
	return (new_opt((t_flags){0, 0, 0, 0, 0, 0}, NULL));
}

t_opt			*symmetric_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	new = get_sym_args(ac, av, now);
	add_to_end_lst(new, &opts);
	return (opts);
}

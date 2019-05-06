/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:04:37 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/06 15:26:59 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "symmetric/symmetric.h"
#include <stdio.h>
#include <unistd.h>

static void		get_sym_opt(char **av, int *now, t_opt *opt)
{
	(void)av;
	(void)now;
	(void)opt;
}

static t_opt	*get_sym_args(const int ac, char **av, int now)
{
	t_opt		opt;
	t_sym_key	*k;

	(void)av;
	k = NULL;
	opt = (t_opt){NULL, {0, 0, 0, 0, 0}, NULL};
	while (now < ac)
	{
		if (av[now][0] == '-')
			get_sym_opt(av, &now, &opt);
		now++;
	}
	if (k == NULL)
		k = new_key(get_pass("enter your password: "), 0, 0);
	return (new_opt((t_flags){0,0,0,0,0}, NULL));
}

t_opt	*symmetric_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	new = get_sym_args(ac, av, now);
	add_to_end_lst(new, &opts);
	return (opts);
}
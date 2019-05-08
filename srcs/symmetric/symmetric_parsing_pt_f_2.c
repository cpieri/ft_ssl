/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing_pt_f_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:21:15 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/08 11:03:36 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/symmetric.h"
#include "ft_ssl.h"

void	get_sym_opt_a(char **av, int *now, t_opt *opt, t_sym_key **k)
{
	(void)av;
	(void)now;
	(void)k;
	opt->flags.sym_flags |= e_sym_opt_a;
}

void	get_sym_opt_d(char **av, int *now, t_opt *opt, t_sym_key **k)
{
	(void)k;
	(void)now;
	(void)av;
	if ((opt->flags.sym_flags & e_sym_opt_e) == e_sym_opt_e)
		opt->flags.sym_flags ^= e_sym_opt_e;
	opt->flags.sym_flags |= e_sym_opt_d;
}

void	get_sym_opt_e(char **av, int *now, t_opt *opt, t_sym_key **k)
{
	(void)k;
	(void)now;
	(void)av;
	if ((opt->flags.sym_flags & e_sym_opt_d) != e_sym_opt_d)
		opt->flags.sym_flags |= e_sym_opt_e;
}

void	get_sym_opt_v(char **av, int *now, t_opt *opt, t_sym_key **k)
{
	uint64_t	vector;

	if (av[*now + 1] == NULL || av[*now + 1][0] == '-')
		sym_usage(av[*now]);
	vector = hex2int(av[*now + 1]);
	opt->flags.sym_flags |= e_sym_opt_v;
	if (*k == NULL)
		*k = new_key(NULL, 0, 0, vector);
	else
		(*k)->vect = vector;
	(*now)++;
}

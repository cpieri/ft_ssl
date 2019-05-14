/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing_pt_f_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:21:15 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/14 11:47:49 by cpieri           ###   ########.fr       */
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
	vector = hex2uint64t(av[*now + 1]);
	opt->flags.sym_flags |= e_sym_opt_v;
	if (*k == NULL)
		*k = new_key(NULL, 0, 0, vector);
	else
		(*k)->vect = vector;
	(*now)++;
}

void	get_sym_stdin(t_opt *opt, t_sym_key **k)
{
	const char	*fd_output;

	fd_output = NULL;
	if (opt->data == NULL)
		opt->data = new_data();
	if (opt->data->fd_output != NULL)
		fd_output = opt->data->fd_output;
	if (*k == NULL)
		*k = new_key(get_pass("enter your password: "), 0, 0, 0);
	if (opt->data != NULL && opt->data->data == NULL)
	{
		clean_data(&(opt->data));
		opt->data = get_data(0, NULL);
	}
	opt->data->fd_output = fd_output;
	opt->data->pass = &k;
}

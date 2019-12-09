/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing_pt_f_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:21:15 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/09 14:59:28 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/symmetric.h"
#include "ft_ssl.h"

void	get_sym_opt_k(char **av, int *now, t_opt *opt, t_pbkdf **k)
{
	uint64_t	key;

	if (av[*now + 1] == NULL || av[*now + 1][0] == '-')
		sym_usage(av[*now]);
	key = hex2uint64t(av[*now + 1]);
	opt->flags.sym_flags |= e_sym_opt_k;
	if ((opt->flags.sym_flags & e_sym_opt_s) == e_sym_opt_s)
		opt->flags.sym_flags ^= e_sym_opt_s;
	if (*k == NULL)
		*k = new_key(NULL, 0, key, 0);
	else
		(*k)->key = key;
	(*now)++;
}

void	get_sym_opt_p(char **av, int *now, t_opt *opt, t_pbkdf **k)
{
	char	*pass;

	if ((pass = av[*now + 1]) == NULL || pass[0] == '-')
		sym_usage(av[*now]);
	if ((opt->flags.sym_flags & e_sym_opt_k) != e_sym_opt_k)
	{
		opt->flags.sym_flags |= e_sym_opt_p;
		if (*k == NULL)
			*k = new_key((uint8_t*)pass, 0, 0, 0);
		else
			(*k)->pass = (uint8_t*)pass;
		(*now)++;
	}
}

void	get_sym_opt_s(char **av, int *now, t_opt *opt, t_pbkdf **k)
{
	uint64_t	salt;

	if (av[*now + 1] == NULL || av[*now + 1][0] == '-')
		sym_usage(av[*now]);
	if ((opt->flags.sym_flags & e_sym_opt_k) != e_sym_opt_k)
	{
		salt = hex2uint64t(av[*now + 1]);
		opt->flags.sym_flags |= e_sym_opt_s;
		if (*k == NULL)
			*k = new_key(NULL, salt, 0, 0);
		else
			(*k)->salt = salt;
		(*now)++;
	}
}

void	get_sym_opt_v(char **av, int *now, t_opt *opt, t_pbkdf **k)
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

void	get_sym_stdin(t_opt *opt, t_pbkdf **k)
{
	const char	*fd_output;

	fd_output = NULL;
	if (opt->data == NULL)
		opt->data = new_data();
	if (opt->data->fd_output != NULL)
		fd_output = opt->data->fd_output;
	if (opt->data != NULL && opt->data->data == NULL)
	{
		clean_data(&(opt->data));
		opt->data = get_data(0, NULL);
	}
	opt->data->fd_output = fd_output;
	opt->data->pass = *k;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing_pt_f.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:34:06 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/20 12:17:43 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/symmetric.h"
#include "ft_ssl.h"

void	get_sym_opt_i(char **av, int *now, t_opt *opt, t_pbkdf **k)
{
	char		*fd;
	const char	*fd_output;

	(void)k;
	fd_output = NULL;
	if ((fd = av[*now + 1]) == NULL || fd[0] == '-')
		sym_usage(av[*now]);
	opt->flags.sym_flags |= e_sym_opt_i;
	if (opt->data != NULL && fd != NULL)
	{
		if (opt->data->fd_output != NULL)
			fd_output = opt->data->fd_output;
		clean_data(&(opt->data));
	}
	opt->data = get_data(open_fd(fd), fd);
	opt->data->fd_output = fd_output;
	(*now)++;
}

void	get_sym_opt_o(char **av, int *now, t_opt *opt, t_pbkdf **k)
{
	char	*fd_output;

	(void)k;
	if ((fd_output = av[*now + 1]) == NULL || fd_output[0] == '-')
		sym_usage(av[*now]);
	opt->flags.sym_flags |= e_sym_opt_o;
	if (opt->data == NULL)
		opt->data = new_data();
	opt->data->fd_output = fd_output;
	(*now)++;
}

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
		{
			(*k)->salt = salt;
			regen_key(k);
		}
		(*now)++;
	}
}

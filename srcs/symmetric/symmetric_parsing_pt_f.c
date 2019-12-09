/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing_pt_f.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:34:06 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/09 14:14:01 by cpieri           ###   ########.fr       */
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

void	get_sym_opt_a(char **av, int *now, t_opt *opt, t_pbkdf **k)
{
	(void)av;
	(void)now;
	(void)k;
	opt->flags.sym_flags |= e_sym_opt_a;
}

void	get_sym_opt_d(char **av, int *now, t_opt *opt, t_pbkdf **k)
{
	(void)k;
	(void)now;
	(void)av;
	if ((opt->flags.sym_flags & e_sym_opt_e) == e_sym_opt_e)
		opt->flags.sym_flags ^= e_sym_opt_e;
	opt->flags.sym_flags |= e_sym_opt_d;
}

void	get_sym_opt_e(char **av, int *now, t_opt *opt, t_pbkdf **k)
{
	(void)k;
	(void)now;
	(void)av;
	if ((opt->flags.sym_flags & e_sym_opt_d) != e_sym_opt_d)
		opt->flags.sym_flags |= e_sym_opt_e;
}

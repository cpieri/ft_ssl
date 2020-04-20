/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing_pt_f_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:21:15 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/20 10:44:40 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/symmetric.h"
#include "ft_ssl.h"
#include <stdio.h>

void	get_sym_opt_p(char **av, int *now, t_opt *opt, t_evp **k)
{
	char	*pass;

	if ((pass = av[*now + 1]) == NULL || pass[0] == '-')
		sym_usage(av[*now]);
	if ((opt->flags.sym_flags & e_sym_opt_k) != e_sym_opt_k)
	{
		opt->flags.sym_flags |= e_sym_opt_p;
		if (*k == NULL)
			*k = new_t_evp((uint8_t*)pass, 0, 0, 0);
		else
			(*k)->pass = (uint8_t*)pass;
		(*k)->pass_len = ft_strlen(pass);
		(*now)++;
	}
}

void	get_sym_opt_s(char **av, int *now, t_opt *opt, t_evp **k)
{
	char		*salt;
	uint64_t	nb;

	nb = 0;
	if ((salt = av[*now + 1]) == NULL || av[*now + 1][0] == '-')
		sym_usage(av[*now]);
	if ((opt->flags.sym_flags & e_sym_opt_k) != e_sym_opt_k)
	{
		if (ft_ishexa(salt) == 1)
		{
			nb = swap_uint64t(hex2uint64t(salt));
			salt = ft_memdup(&nb, sizeof(uint64_t));
		}
		else
			exit_msg("ft_ssl: invalid hex salt value");
		opt->flags.sym_flags |= e_sym_opt_s;
		if (*k == NULL)
			*k = new_t_evp(NULL, salt, 0, 0);
		else
			(*k)->salt = salt;
		(*k)->salt_len = 8;
		(*now)++;
	}
}

void	get_sym_opt_k(char **av, int *now, t_opt *opt, t_evp **k)
{
	uint64_t	key_uint;
	char		*key;

	if ((key = av[*now + 1]) == NULL || av[*now + 1][0] == '-')
		sym_usage(av[*now]);
	if (ft_ishexa(key) == 1)
	{
		key_uint = swap_uint64t(hex2uint64t(key));
		key = ft_memdup(&key_uint, sizeof(uint64_t));
	}
	opt->flags.sym_flags |= e_sym_opt_k;
	if ((opt->flags.sym_flags & e_sym_opt_s) == e_sym_opt_s)
		opt->flags.sym_flags ^= e_sym_opt_s;
	if (*k == NULL)
		*k = new_t_evp(NULL, 0, key, 0);
	else
		(*k)->key = key;
	(*k)->dk_len = 8;
	(*now)++;
}

void	get_sym_opt_v(char **av, int *now, t_opt *opt, t_evp **k)
{
	char		*vect;
	uint64_t	vector;

	vector = 0;
	if ((vect = av[*now + 1]) == NULL || av[*now + 1][0] == '-')
		sym_usage(av[*now]);
	if (ft_ishexa(vect) == 1)
	{
		vector = swap_uint64t(hex2uint64t(vect));
		vect = ft_memdup(&vector, sizeof(uint64_t));
	}
	opt->flags.sym_flags |= e_sym_opt_v;
	if (*k == NULL)
		*k = new_t_evp(NULL, 0, 0, vect);
	else
		(*k)->vect = vect;
	(*k)->iv_len = 8;
	(*now)++;
}

void	get_sym_stdin(t_opt *opt, t_evp **k)
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

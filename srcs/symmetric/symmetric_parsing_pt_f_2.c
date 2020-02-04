/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing_pt_f_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:21:15 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/04 14:41:55 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/symmetric.h"
#include "ft_ssl.h"

void	get_sym_opt_k(char **av, int *now, t_opt *opt, t_evp **k)
{
	uint64_t	key;

	if (av[*now + 1] == NULL || av[*now + 1][0] == '-')
		sym_usage(av[*now]);
	key = hex2uint64t(av[*now + 1]);
	opt->flags.sym_flags |= e_sym_opt_k;
	if ((opt->flags.sym_flags & e_sym_opt_s) == e_sym_opt_s)
		opt->flags.sym_flags ^= e_sym_opt_s;
	if (*k == NULL)
		*k = new_t_evp(NULL, 0, key, 0);
	else
		(*k)->key = &key;
	(*now)++;
}

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
	unsigned char	*salt;
	size_t			len;
	uint64_t		nb;

	len = 0;
	nb = 0;
	if ((salt = (unsigned char*)av[*now + 1]) == NULL || av[*now + 1][0] == '-')
		sym_usage(av[*now]);
	if ((opt->flags.sym_flags & e_sym_opt_k) != e_sym_opt_k)
	{
		if (ft_ishexa((char*)salt) == 1)
		{
			nb = swap_uint64t(hex2uint64t((char*)salt));
			salt = ft_memdup(&nb, sizeof(uint64_t));
			len = sizeof(uint64_t);
		}
		len = ft_strlen((char*)salt);
		opt->flags.sym_flags |= e_sym_opt_s;
		if (*k == NULL)
			*k = new_t_evp(NULL, salt, 0, 0);
		else
			(*k)->salt = salt;
		(*k)->salt_len = len;
		(*now)++;
	}
}

void	get_sym_opt_v(char **av, int *now, t_opt *opt, t_evp **k)
{
	unsigned char	*vect;
	size_t			len;
	uint64_t		vector;

	len = 0;
	vector = 0;
	if ((vect = (unsigned char*)av[*now + 1]) == NULL || av[*now + 1][0] == '-')
		sym_usage(av[*now]);
	if (ft_ishexa((char*)vect) == 1)
	{
		vector = hex2uint64t((char*)vect);
		vect = ft_memdup(&vector, sizeof(uint64_t));
		len = sizeof(uint64_t);
	}
	opt->flags.sym_flags |= e_sym_opt_v;
	if (*k == NULL)
		*k = new_t_evp(NULL, 0, 0, vect);
	else
		(*k)->vect = vect;
	(*k)->iv_len = len;
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

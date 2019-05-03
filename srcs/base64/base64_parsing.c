/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:56:03 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/03 15:01:37 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "base64/base64.h"

static void		get_b64_opt(char **av, int *now, t_opt *t_o, char **output)
{
	size_t		len_now;
	size_t		i;

	i = 0;
	len_now = ft_strlen(av[*now]);
	while (++i < len_now)
	{
		if (av[*now][i] == 'e' || av[*now][i] == 'd')
			get_b64_ed(&(t_o->data), &(t_o->flags),
			(av[*now + 1] != NULL ? av[*now + 1] : NULL), av[*now][i]);
		else if (av[*now][i] == 'i')
			get_b64_i(&(t_o->data), &(t_o->flags), av[(*now) + 1], now);
		else if (av[*now][i] == 'o')
		{
			t_o->flags.b64_flags |= e_base64_outputf;
			*output = (av[(*now) + 1] != NULL) ? av[(*now) + 1] : NULL;
			(*now)++;
		}
	}
}

static t_opt	*get_base64_args(const int ac, char **av, int now)
{
	t_opt	t_o;
	char	*fd_output;

	fd_output = NULL;
	t_o = (t_opt){NULL, {0, 0, 0, 0, 0}, NULL};
	while (now < ac)
	{
		if (av[now][0] == '-')
			get_b64_opt(av, &now, &t_o, &fd_output);
		else
			get_b64_ed(&(t_o.data), &(t_o.flags), av[now], 'e');
		now++;
	}
	if (t_o.data == NULL)
		get_b64_ed(&(t_o.data), &(t_o.flags), NULL, 'e');
	return (new_opt_fd(t_o.flags, t_o.data, fd_output));
}

t_opt			*base64_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	new = get_base64_args(ac, av, now);
	add_to_end_lst(new, &opts);
	return (opts);
}

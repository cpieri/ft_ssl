/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:56:03 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 19:30:10 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

static t_opt	*check_b64_flags(size_t len, t_flags *flags, char **av, int now)
{
	size_t	i;
	t_data	*data;
	t_opt	*new;

	i = 0;
	new = NULL;
	while (++i < len)
	{
		if (new != NULL)
			break ;
		if (av[now][i] == 'o')
		{
			flags->b64_flags |= e_base64_outputf;
			if (data == NULL)
			{
				flags->b64_flags |= e_base64_encode;
				data = get_data(0, NULL);
			}
			new = new_opt(*flags, data);
			new->fd_output = av[now + 1];
			return (new);
		}
		else if (av[now][i] == 'i')
		{
			flags->b64_flags |= e_base64_inputf;
			data = get_file(open_fd(av[now + 1]), av[now + 1]);
			now += 2;
		}
		else if (av[now][i] == 'e')
		{
			flags->b64_flags |= e_base64_encode;
			data = get_data(0, NULL);
		}
		else if (av[now][i] == 'd' || av[now][i] == 'D')
		{
			flags->b64_flags |= e_base64_decode;
			data = get_data(0, NULL);
		}
	}
	new = new_opt(*flags, data);
	return (new);
}

static t_opt	*get_b64_args(char **av, int now)
{
	t_flags		flags;
	t_opt		*new;
	size_t		len;

	new = NULL;
	flags.b64_flags |= e_base64_encode;
	if (av[now][0] == '-')
	{
		len = ft_strlen(av[now]);
		new = check_b64_flags(len, &flags, av, now);
	}
	return (new);
}

t_opt	*base64_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt		*new;
	t_flags		flags;

	if (ac < 3)
	{
		flags.b64_flags |= e_base64_encode;
		ft_membits(&(flags.b64_flags), 0, sizeof(uint32_t));
		new = new_opt(flags, get_data(0, NULL));
	}
	else
		new = get_b64_args(av, now);
	add_to_end_lst(new, &opts);
	now++;
	if (now < ac)
		opts = base64_opts(ac, av, opts, now);
	return (opts);
}

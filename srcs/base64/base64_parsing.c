/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:56:03 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/12 11:31:43 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

t_opt	*get_base64_args(const int ac, char **av, int now)
{
	t_opt	*new;
	t_flags	flags;
	t_data	*data;
	char	*fd_output = NULL;
	size_t	len_now;
	size_t	i;

	if (ac < 3)
	{
		flags.b64_flags |= e_base64_encode;
		data = get_data(0, NULL);
	}
	while (now < ac)
	{
		printf("av: %s\n", av[now]);
		if (av[now][0] == '-')
		{
			i = 0;
			len_now = ft_strlen(av[now]);
			while (++i < len_now)
			{
				if (av[now][i] == 'e')
				{
					flags.b64_flags |= e_base64_encode;
					if (data == NULL)
						data = get_data(0, NULL);
				}
				else if (av[now][i] == 'd' || av[now][i] == 'D')
				{
					flags.b64_flags |= e_base64_decode;
					if (data == NULL)
						data = get_data(0, NULL);
				}
				else if (av[now][i] == 'i')
				{
					flags.b64_flags |= e_base64_inputf;
					if (data != NULL)
						clean_data(&data);
					data = get_data(open_fd(av[now + 1]), av[now + 1]);
					now++;
				}
				else if (av[now][i] == 'o')
				{
					flags.b64_flags |= e_base64_inputf;
					if (av[now + 1] != NULL)
						fd_output = av[now + 1];
					else
						fd_output = NULL;
					now++;
				}
			}
		}
		else
		{
			flags.b64_flags |= e_base64_encode;
			data = get_file(open_fd(av[now]), av[now]);
			break ;
		}
		now++;
	}
	if (data == NULL)
	{
		flags.b64_flags |= e_base64_encode;
		data = get_data(0, NULL);
	}
	new = new_opt(flags, data);
	if (fd_output != NULL && new != NULL)
		new->fd_output = fd_output;
	return (new);
}

t_opt	*base64_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	new = get_base64_args(ac, av, now);
	add_to_end_lst(new, &opts);
	return (opts);
}

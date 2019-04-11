/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 12:47:58 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_parse			parsing(const int ac, char **av)
{
	t_parse		parse;
	int			i;
	int			now;

	now = 1;
	i = 0;
	parse = (t_parse){NULL, NULL, NULL, NULL, NULL};
	while (g_all_cmd[i].cmd != NULL)
	{
		if (ft_strcmp(g_all_cmd[i].cmd, av[now]) == 0)
		{
			parse = g_all_cmd[i];
			parse.lst_opts = parse.fparse(ac, av, NULL, now + 1);
			return (parse);
		}
		i++;
	}
	print_usage(2, av[1]);
	return (parse);
}

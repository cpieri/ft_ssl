/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/08 11:47:33 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ssl_md5.h"

int		check_command(const char *cmd)
{
	if (ft_strcmp("md5", cmd) == 0)
		return (MD5);
	else if (ft_strcmp("sha256", cmd) == 0)
		return (SHA256);
	return (FAILURE);
}

int		read_stdin(void)
{
	char	data[1];
	char	*line;

	while (get_next_line(0, &line))
	{
		//printf("data: %s", data);
		printf("data: %s", line);
		//data = ft_strdup(line);
		free(line);
	}
	printf("data end: %s", line);
	return (0);//(data);
}

int		parse_opts(int ac, char **av, t_parse *parsing)
{
	t_opt		*opt;

	(void)parsing;
	if (!(opt = (t_opt*)ft_memalloc(sizeof(t_opt) * 1)))
		exit_error("Error: Funct parse_opts: Memalloc failed");
	else if (ac < 3 || ft_strcmp(av[2], "-p") == 0)
		read_stdin();
	return (SUCCESS);
}

int		parsing(int ac, char **av)
{
	t_parse		*parsing;

	if (!(parsing = (t_parse*)ft_memalloc(sizeof(t_parse) * 1)))
		exit_error("Error: Func Parsing: Memalloc failed");
	else if ((parsing->hash_type = check_command(av[1])) == FAILURE)
		print_usage(INVALID_CMD, av[1]);
	parse_opts(ac, av, parsing);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/08 14:24:08 by cpieri           ###   ########.fr       */
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

int		parse_opts(const int ac, char **av, t_parse *parsing)
{
	return (SUCCESS);
}

/*int		parse_opts(const int ac, char **av, t_parse *parsing)
  {
  t_opt		*opt;
  char		*data;

  data = NULL;
  if (!(opt = (t_opt*)ft_memalloc(sizeof(t_opt) * 1)))
  exit_error("Error: Funct parse_opts: Memalloc failed");
  opt->next = NULL;
  if (ac < 3 || ft_strcmp(av[2], "-p") == 0)
  get_data(0, &data);
  opt->data = ft_strdup(data);
  ft_strdel(&data);
  printf("data: %s", opt->data);
  printf("hash_type: %d", parsing->hash_type);
  return (SUCCESS);
  }*/

int		parsing(int ac, char **av)
{
	t_parse		*parsing;

	if (!(parsing = (t_parse*)ft_memalloc(sizeof(t_parse) * 1)))
		exit_error("Error: Func parsing: Memalloc failed");
	else if ((parsing->hash_type = check_command(av[1])) == FAILURE)
		print_usage(INVALID_CMD, av[1]);
	else if (!(parsing->lst_opts = (t_opt**)ft_memalloc(sizeof(t_opt*) * 1)))
		exit_error("Error: Func parsing: Memalloc failed");
	parse_opts(ac, av, parsing);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:29:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/01/25 17:58:00 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

static int	check_command(const char *s)
{
	if (ft_strcmp("md5", s) == 0)
		return (1);
	else if (ft_strcmp("sha256", s) == 0)
		return (2);
	return (-1);
}

int		parsing(int ac, char **av)
{
	int		check;

	check = check_command(av[1]);
	if (check == -1)
		print_usage(2, av[1]);
	if (check == 1 && ac >= 3)
		md5(av[2]);
	return (0);
}

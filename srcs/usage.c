/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:06:36 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/07 19:33:17 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

static void	invalid_command(const char *command)
{
	ft_putstr_fd("ft_ssl: Error: ", 2);
	ft_putstr_fd(command, 2);
	ft_putendl_fd(" is an invalid command.", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Standard commands:", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Message Digest commands:", 2);
	ft_putendl_fd("md5", 2);
	ft_putendl_fd("sha256", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Cipher commands:", 2);
}

void		print_usage(const int usage_int, const char *command)
{
	if (usage_int == 1)
		ft_putendl_fd("usage: ft_ssl command [command opts] [command args]", 2);
	if (usage_int == 2 && command != NULL)
		invalid_command(command);
	exit(FAILURE);
}

void		exit_error(const char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(FAILURE);
}

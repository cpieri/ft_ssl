/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:06:36 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/06 14:42:15 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <string.h>

static void	invalid_command(const char *command)
{
	int		i;

	i = 0;
	ft_putstr_fd("ft_ssl: Error: ", 2);
	ft_putstr_fd(command, 2);
	ft_putendl_fd(" is an invalid command.", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Standard commands:", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Message Digest commands:", 2);
	while (g_hash_cmd[i] != NULL)
		ft_putendl_fd(g_hash_cmd[i++], 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Cipher commands:", 2);
	i = 0;
	while (g_cipher_cmd[i] != NULL)
		ft_putendl_fd(g_cipher_cmd[i++], 2);
}

void		print_usage(const int usage_int, const char *command)
{
	if (usage_int == 1)
		ft_putendl_fd("usage: ft_ssl command [command opts] [command args]", 2);
	if (usage_int == 2 && command != NULL)
		invalid_command(command);
	exit(FAILURE);
}

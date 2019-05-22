/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:14:10 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/22 09:33:52 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_name(const char *fd_name, t_flags flags)
{
	if (flags.s == 1)
	{
		ft_putchar('\"');
		ft_putstr(fd_name);
		ft_putchar('\"');
	}
	else
		ft_putstr(fd_name);
}

void		printing_hash(t_data *data, const char *hash_type, t_flags flags)
{

	if (flags.r == 0 && flags.q == 0 && data->fd_name != NULL)
	{
		ft_putstr(hash_type);
		ft_putstr(" (");
		print_name(data->fd_name, flags);
		ft_putstr(") = ");
	}
	else if (flags.p == 1)
		ft_putstr(data->data);
	ft_putstr((char*)data->data_2_print);
	if (flags.r == 1)
	{
		ft_putchar(' ');
		print_name(data->fd_name, flags);
	}
	ft_putchar('\n');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:14:10 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/29 14:08:50 by cpieri           ###   ########.fr       */
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

static void	print_hash(t_hash *f_hash)
{
	size_t	y;
	uint8_t	*p;
	int		i;

	y = -1;
	while (++y < f_hash->nb_word)
	{
		i = -1;
		p = (uint8_t*)&f_hash->h[y];
		while (++i < 4)
			ft_puthexa(p[i]);
	}
}

void		printing_hash(t_data *data, const char *hash_type, t_flags flags)
{
	t_hash	*f_hash;

	f_hash = (t_hash*)data->data_2_print;
	if (flags.r == 0 && flags.q == 0 && data->fd_name != NULL)
	{
		ft_putstr(hash_type);
		ft_putstr(" (");
		print_name(data->fd_name, flags);
		ft_putstr(") = ");
	}
	else if (flags.p == 1)
		ft_putstr(data->data);
	print_hash(f_hash);
	if (flags.r == 1)
	{
		ft_putchar(' ');
		print_name(data->fd_name, flags);
	}
	ft_putchar('\n');
}

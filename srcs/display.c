/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:14:10 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/18 16:42:50 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

static void	print_name(const char *fd_name, char *hash_type, t_flags flags)
{
	ft_putstr(hash_type);
	ft_putstr(" (");
	if (flags.s == 1)
	{
		ft_putchar('\"');
		ft_putstr(fd_name);
		ft_putchar('\"');
	}
	else
		ft_putstr(fd_name);
	ft_putstr(") = ");
}

static void	print_hash(uint8_t *p)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (p[i] < 16)
			ft_putchar('0');
		ft_puthexa(p[i++]);
	}
}

void		printing_hash(t_data *data, char *hash_type, t_flags flags)
{
	size_t	i;
	uint8_t	*p;

	i = 0;
	if (flags.r == 0 && flags.q == 0 && data->fd_name != NULL)
		print_name(data->fd_name, hash_type, flags);
	else if (data->fd_name == NULL)
		ft_putstr(data->data);
	while (i < data->f_hash->nb_word)
	{
		p = (uint8_t*)&data->f_hash->h[i];
		print_hash(p);
		i++;
	}
	if (flags.r == 1)
	{
		ft_putchar(' ');
		ft_putstr(data->fd_name);
	}
	ft_putchar('\n');
}

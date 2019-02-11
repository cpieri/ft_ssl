/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:18:34 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/11 17:26:06 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include <stdio.h>

static t_block	*create_all_blocks(const int nb, t_block *lst)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		add_2_end_lstblocks(new_block(), &lst);
		i++;
	}
	return (lst);
}

void			md5(char *data)
{
	size_t		len;
	size_t		nb_bits;
	t_block		*blocks;

	blocks = NULL;
	len = ft_strlen(data);
	nb_bits = len * 8;
	blocks = create_all_blocks(nb_bits / 512, blocks);

}

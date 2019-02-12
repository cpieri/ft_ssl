/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:18:34 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/12 14:25:04 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include <stdio.h>

static t_block	*create_all_blocks(const int nb, t_block *lst)
{
	int		i;

	i = 0;
	ft_putnbr(nb), ft_putchar('\n');
	while (i <= nb)
	{
		add_2_end_lstblocks(new_block(), &lst);
		i++;
	}
	return (lst);
}

void			copy_data_to_lst(char *data, t_block **lst_blocks)
{
	int		i;
	t_block	*lst;

	i = 0;
	lst = *lst_blocks;
	while (lst)
	{
		while (i < BLOCK_TAB_LEN)
		{
			lst->tab[i] = (uint32_t)data[i]; 
			i++;
		}
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
}

void			padding(char *data, size_t len, t_block **lst)
{
	(void)lst;
	data[len] = data[len] | 1 << 7;
	copy_data_to_lst(data, lst);
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
	padding(data, len, &blocks);
}

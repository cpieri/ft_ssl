/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:18:34 by cpieri            #+#    #+#             */
/*   Updated: 2019/01/26 18:44:47 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include <stdio.h>

static int		padding(t_md5 md5)
{
	t_block		*blocks;
	int			i;
	int			y;

	i = 0;
	if (!(blocks = (t_block*)malloc(sizeof(t_block) * (md5.nb_blocks + 1))))
		return (FAILURE);
	while (i <= md5.nb_blocks)
	{
		y = 0;
		while (y < BLOCK_TAB_LEN)
		{
			blocks->tab[y++] = 0;
		}
		i++;
	}
	int new_len;
	for(new_len = md5.org_len *8 + 1; new_len%512!=448; new_len++);
	printf("new_len = %d\n", new_len);
	new_len /= 8;
	printf("new_len = %d\n", new_len);
	return (SUCCESS);
}

void			md5(char *s)
{
	t_md5		md5;
	const int	op_tabs[OP_TAB_LEN] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
		22, 7, 12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14,
		20, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
		15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

	(void)op_tabs;
	md5.org_len = ft_strlen(s);
	md5.org_nb_bits = md5.org_len * 8;
	md5.nb_blocks = md5.org_nb_bits / 512;
	md5.org_str = ft_strdup(s);
	printf("len: %zu\n", md5.org_len);
	padding(md5);
}

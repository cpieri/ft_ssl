/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:18:34 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/12 18:48:30 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include <stdio.h>

static void	padding(t_hash *e, char *data)
{
	e->init_len = ft_strlen(data);
	e->new_len = e->init_len * 8 + 1;
	e->nb_bits = e->init_len * 8;
	while ((e->new_len % 512) != 448)
		e->new_len++;
	e->new_len /= 8;
	if (!(e->str_bits = (uint8_t*)ft_memalloc(sizeof(uint8_t) * e->new_len + 64)))
		return ;
	ft_memcpy(e->str_bits, data, e->init_len);
	e->str_bits[e->init_len] |= 1 << 7;
	ft_memcpy(e->str_bits + e->new_len, &e->nb_bits, 4);
}

void		md5(char *data)
{
	t_hash	e;

	padding(&e, data);
	//ft_mem_bits(e.str_bits, e.new_len);
	//printf("init_len: %zu, new_len: %zu\n",e.init_len, e.new_len);
}

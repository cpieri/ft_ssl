/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:46:38 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/08 11:55:22 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	padding_512b(t_padding *p, char *data, size_t len_data)
{
	size_t		size_malloc;

	p->init_len = len_data;
	p->new_len = p->init_len;
	p->nb_bits = p->init_len * 8;
	while ((p->new_len % 64) != 56)
		p->new_len++;
	size_malloc = p->new_len + 8;
	if (!(p->str_bits = (uint8_t*)ft_memalloc(sizeof(uint8_t) * size_malloc)))
	{
		ft_memdel((void**)p->str_bits);
		ft_abort("Malloc Failed: padding.c:25:padding_512b()");
	}
	ft_memcpy(p->str_bits, data, p->init_len);
	p->str_bits[p->init_len] |= 1 << 7;
	ft_memcpy(p->str_bits + p->init_len, &p->nb_bits, 4);
	p->offest = 0;
}

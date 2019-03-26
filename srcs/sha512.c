/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:55:07 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/26 18:37:45 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha512.h"

static void		padding_sha512(t_padding *p, void *data, size_t len)
{
	size_t	size_32;
	size_t	i;

	size_32 = sizeof(uint32_t);
	p->init_len = len;
	p->nb_bits = len * 8;
	p->new_len = (896 - (p->nb_bits + 1)) % 1024;
	p->new_len += p->nb_bits + 128 + 1;
	p->new_len /= 32;
	if (!(p->msg32 = (uint32_t*)ft_memalloc(sizeof(uint32_t) * p->new_len)))
		ft_abort("malloc failed");
	i = -1;
	while (++i <= (len / 4))
	{
		ft_memcpy(&p->msg32[i], data + (i * 4), size_32);
	}
	ft_membits(p->msg32, p->new_len, sizeof(uint32_t));
}

t_hash			*sha512(void *data, size_t len_data)
{
	t_hash		*f_hash;
	t_sha512	t;

	ft_membits(data, len_data, sizeof(char));
	padding_sha512(&(t.p), data, len_data);
	f_hash = NULL;
	while (t.p.offest < t.p.new_len)
	{
		t.a = t.h0;
		t.b = t.h1;
		t.c = t.h2;
		t.d = t.h3;
		t.e = t.h4;
		t.f = t.h5;
		t.g = t.h6;
		t.h = t.h7;
		//t.w = create_w512(t.p.msg8, t.p.offest);
		//calc_sha512(&t);
		ft_memdel((void**)&(t.w));
		t.p.offest += 128;
	}
	//	f_hash = set_hash2sha512(&t);
	return (f_hash);
}

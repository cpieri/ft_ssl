/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:55:07 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/22 19:01:14 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha512.h"

static void		*padding_sha512(t_padding *p, void *data, size_t len_data)
{
	p->init_len = len_data;
	p->nb_bits = len_data * 8;
	p->new_len = ()
}

t_hash			*sha512(void *data, size_t len_data)
{
	t_hash		*f_hash;
	t_sha512	t;

	padding_sha512(&(t.p), data, len_data);
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
		t.w = create_w512(t.p.msg8, t.p.offest);
		calc_sha512(&t);
		ft_memdel((void**)&(t.w));
		t.p.offest += 128;
	}
	f_hash = set_hash2sha512(&t);
	return	(f_hash);
}

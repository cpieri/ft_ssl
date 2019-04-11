/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:18:34 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 14:12:25 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/md5.h"

static void		padding_md5(t_padding *p, char *data, size_t len)
{
	int		i;

	i = -1;
	p->init_len = len;
	p->nb_bits = len * 8;
	p->new_len = (448 - (p->nb_bits + 1)) % 512;
	p->new_len += p->nb_bits + 64 + 1;
	p->new_len /= 8;
	if (!(p->msg8 = (uint8_t*)ft_memalloc(sizeof(uint8_t) * p->new_len)))
		ft_abort("malloc failed");
	ft_memcpy(p->msg8, data, len);
	p->msg8[len] |= 1 << 7;
	ft_memcpy(p->msg8 + p->new_len - 8, &p->nb_bits, 8);
	p->offest = 0;
}

static void		calc_sum(t_md5 *e)
{
	int			i;
	t_md5_utils	tool;
	uint32_t	tmp;
	uint32_t	tmp2;

	i = 0;
	while (i < 64)
	{
		if (i >= 0 && i <= 15)
			tool = func_f(e->b, e->c, e->d, i);
		else if (i >= 16 && i <= 31)
			tool = func_g(e->b, e->c, e->d, i);
		else if (i >= 32 && i <= 47)
			tool = func_h(e->b, e->c, e->d, i);
		else if (i >= 48 && i <= 63)
			tool = func_i(e->b, e->c, e->d, i);
		tmp = e->d;
		e->d = e->c;
		e->c = e->b;
		tmp2 = left_rotate((e->a + tool.f + g_k_md5[i] + e->w[tool.g]),
				g_r_md5[i]);
		e->b = tmp2 + e->b;
		e->a = tmp;
		i++;
	}
}

void			*md5(void *data, size_t len_data)
{
	t_md5		e;
	t_hash		*f_hash;

	e = (t_md5){.h0 = MD5_H0, .h1 = MD5_H1, .h2 = MD5_H2, .h3 = MD5_H3};
	padding_md5(&(e.p), data, len_data);
	while (e.p.offest < e.p.new_len)
	{
		e.w = (uint32_t*)(e.p.msg8 + e.p.offest);
		e.a = e.h0;
		e.b = e.h1;
		e.c = e.h2;
		e.d = e.h3;
		calc_sum(&e);
		e.h0 += e.a;
		e.h1 += e.b;
		e.h2 += e.c;
		e.h3 += e.d;
		e.p.offest += 64;
	}
	f_hash = set_hash2md5(&e);
	return (f_hash);
}

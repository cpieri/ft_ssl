/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 08:04:36 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/31 08:14:52 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/sha1.h"

static void		padding_sha1(t_padding *p, char *data, size_t len)
{
	int		i;

	i = -1;
	p->init_len = len;
	p->nb_bits = len * 8;
	p->new_len = (448 - (p->nb_bits + 1)) % 512;
	p->new_len += p->nb_bits + 64 + 1;
	p->new_len /= 8;
	if (!(p->msg8 = (uint8_t*)ft_memalloc(sizeof(uint8_t) * p->new_len)))
		ft_abort("ft_ssl: sha1: malloc failed");
	ft_memcpy(p->msg8, data, len);
	p->msg8[len] |= 1 << 7;
	while (++i < 8)
		p->msg8[p->new_len - 8 + i] = ((uint8_t*)&(p->nb_bits))[7 - i];
	p->offest = 0;
}

static void		calc_sha1(t_sha1 *e)
{
	int				i;
	uint32_t		tmp;
	t_sha1_utils	tool;

	i = 0;
	while (i < 80)
	{
		if (i >= 0 && i <= 19)
			tool = func_sha1_f(e->b, e->c, e->d);
		else if (i >= 20 && i <= 39)
			tool = func_sha1_g(e->b, e->c, e->d);
		else if (i >= 40 && i <= 59)
			tool = func_sha1_h(e->b, e->c, e->d);
		else if (i >= 60 && i <= 79)
			tool = func_sha1_i(e->b, e->c, e->d);
		tmp = left_rotate(e->a, 5) + tool.f + e->e + tool.k + e->w[i];
		e->e = e->d;
		e->d = e->c;
		e->c = left_rotate(e->b, 30);
		e->b = e->a;
		e->a = tmp;
		i++;
	}
}

static uint32_t	*create_sha1_w(void *msg_8, size_t offest)
{
	int			i;
	uint32_t	*w;

	if (!(w = (uint32_t*)ft_memalloc(sizeof(uint32_t) * 80)))
		return (NULL);
	i = -1;
	while (++i < 16)
	{
		ft_memcpy(&(w[i]), msg_8 + offest + (i * 4), sizeof(uint32_t));
		w[i] = swap_uint32t(w[i]);
	}
	while (i < 80)
	{
		w[i] = left_rotate((w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16]), 1);
		i++;
	}
	return (w);
}

void			*sha1(void *data, size_t len_data)
{
	t_sha1		e;
	t_hash		*sum;

	e = (t_sha1){.h0 = SHA1_H0, .h1 = SHA1_H1, .h2 = SHA1_H2, .h3 = SHA1_H3,
		.h4 = SHA1_H4, .w = NULL};
	padding_sha1(&(e.p), data, len_data);
	while (e.p.offest < e.p.new_len)
	{
		e.a = e.h0;
		e.b = e.h1;
		e.c = e.h2;
		e.d = e.h3;
		e.e = e.h4;
		e.w = create_sha1_w(e.p.msg8, e.p.offest);
		calc_sha1(&e);
		ft_memdel((void**)&(e.w));
		e.h0 += e.a;
		e.h1 += e.b;
		e.h2 += e.c;
		e.h3 += e.d;
		e.h4 += e.e;
		e.p.offest += 64;
	}
	sum = set_hash2sha1(&e);
	return (sum);
}

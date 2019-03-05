/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:18:34 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/05 16:34:04 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t	g_r[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21,
	6, 10, 15, 21, 6, 10, 15, 21};

uint32_t	g_k[64] = {
	3614090360, 3905402710, 606105819, 3250441966, 4118548399, 1200080426,
	2821735955, 4249261313, 1770035416, 2336552879, 4294925233, 2304563134,
	1804603682, 4254626195, 2792965006, 1236535329, 4129170786, 3225465664,
	643717713, 3921069994, 3593408605, 38016083, 3634488961, 3889429448,
	568446438, 3275163606, 4107603335, 1163531501, 2850285829, 4243563512,
	1735328473, 2368359562, 4294588738, 2272392833, 1839030562, 4259657740,
	2763975236, 1272893353, 4139469664, 3200236656, 681279174, 3936430074,
	3572445317, 76029189, 3654602809, 3873151461, 530742520, 3299628645,
	4096336452, 1126891415, 2878612391, 4237533241, 1700485571, 2399980690,
	4293915773, 2240044497, 1873313359, 4264355552, 2734768916, 1309151649,
	4149444226, 3174756917, 718787259, 3951481745};

uint32_t	reverse_uint32t(uint32_t nb)
{
	return ((nb >> 24) | ((nb & 0xff0000) >> 8));
}

static uint32_t	left_rotate(uint32_t x, uint32_t nb)
{
	return ((x << nb) | (x >> (32 - nb)));
}

static void	padding(t_md5 *e, char *data, size_t len_data)
{
	size_t	size_malloc;

	e->init_len = len_data;
	e->new_len = e->init_len;
	e->nb_bits = e->init_len * 8;
	while ((e->new_len % 64) != 56)
		e->new_len++;
	size_malloc = e->new_len + 8;
	if (!(e->str_bits = (uint8_t*)ft_memalloc(sizeof(uint8_t) * size_malloc)))
		return ;
	ft_memcpy(e->str_bits, data, e->init_len);
	e->str_bits[e->init_len] |= 1 << 7;
	ft_memcpy(e->str_bits + e->new_len, &e->nb_bits, 4);
}

static void	calc_sum(t_md5 *e)
{
	int			i;
	uint32_t	f;
	uint32_t	g;
	uint32_t	tmp;

	i = 0;
	while (i < 64)
	{
		if (i >= 0 && i <= 15)
		{
			f = func_f(e->b, e->c, e->d);
			g = i;
		}
		else if (i >= 16 && i <= 31)
		{
			f = func_g(e->b, e->c, e->d);
			g = (5 * i + 1) % 16;
		}
		else if (i >= 32 && i <= 47)
		{
			f = func_h(e->b, e->c, e->d);
			g = (3 * i + 5) % 16;
		}
		else if (i >= 48 && i <= 63)
		{
			f = func_i(e->b, e->c, e->d);
			g = (7 * i) % 16;
		}
		tmp = e->d;
		e->d = e->c;
		e->c = e->b;
		e->b = left_rotate((e->a + f + g_k[i] + e->w[g]), g_r[i]) + e->b;
		e->a = tmp;
		i++;
	}
}

void		md5(void *data, size_t len_data)
{
	t_md5	e;
	uint8_t	*p;

	e.h0 = MD5_H0;
	e.h1 = MD5_H1;
	e.h2 = MD5_H2;
	e.h3 = MD5_H3;
	//printf("%x %x %x %x\n", e.h0, e.h1, e.h2, e.h3);
	padding(&e, data, len_data);
	e.offest = 0;
	//printf("%s", data);
	while (e.offest < e.new_len)
	{
		e.w = (uint32_t*)(e.str_bits + e.offest);
		e.a = e.h0;
		e.b = e.h1;
		e.c = e.h2;
		e.d = e.h3;
		calc_sum(&e);
		e.h0 += e.a;
		e.h1 += e.b;
		e.h2 += e.c;
		e.h3 += e.d;
		//printf("%x %x %x %x\n", e.h0, e.h1, e.h2, e.h3);
		e.offest += 64;
	}
	//printf("%x\n", e.h0 & e.h1 & e.h2 & e.h3);
	p=(uint8_t *)&e.h0;
	printf("%x%x%x%x", p[0], p[1], p[2], p[3]);

	p=(uint8_t *)&e.h1;
	printf("%x%x%x%x", p[0], p[1], p[2], p[3]);

	p=(uint8_t *)&e.h2;
	printf("%x%x%x%x", p[0], p[1], p[2], p[3]);

	p=(uint8_t *)&e.h3;
	printf("%x%x%x%x\n", p[0], p[1], p[2], p[3]);
	//ft_mem_bits(e.str_bits, e.new_len);
	printf("init_len: %zu, new_len: %zu\n",e.init_len, e.new_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 08:42:25 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/31 08:08:11 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/sha1.h"
#include <stdio.h>

t_sha1_utils	func_sha1_f(uint32_t b, uint32_t c, uint32_t d)
{
	t_sha1_utils	ret;

	ret.f = ((b & c) | ((~b) & d));
	ret.k = 0x5a827999;
	return (ret);
}

t_sha1_utils	func_sha1_g(uint32_t b, uint32_t c, uint32_t d)
{
	t_sha1_utils	ret;

	ret.f = (b ^ c ^ d);
	ret.k = 0x6ed9eba1;
	return (ret);
}

t_sha1_utils	func_sha1_h(uint32_t b, uint32_t c, uint32_t d)
{
	t_sha1_utils	ret;

	ret.f = ((b & c) | (b & d) | (c & d));
	ret.k = 0x8f1bbcdc;
	return (ret);
}

t_sha1_utils	func_sha1_i(uint32_t b, uint32_t c, uint32_t d)
{
	t_sha1_utils	ret;

	ret.f = (b ^ c ^ d);
	ret.k = 0xca62c1d6;
	return (ret);
}

t_hash			*set_hash2sha1(t_sha1 *e)
{
	t_hash	*ret;

	ft_memdel((void**)&e->p.msg8);
	if (!(ret = (t_hash*)malloc(sizeof(t_hash))))
		return (NULL);
	if (!(ret->h = (uint32_t*)malloc(sizeof(uint32_t) * 5)))
		return (NULL);
	ret->nb_word = 5;
	ret->h[0] = swap_uint32t(e->h0);
	ret->h[1] = swap_uint32t(e->h1);
	ret->h[2] = swap_uint32t(e->h2);
	ret->h[3] = swap_uint32t(e->h3);
	ret->h[4] = swap_uint32t(e->h4);
	return (ret);
}

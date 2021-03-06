/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:34:11 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 11:58:15 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/md5.h"

t_md5_utils	func_f(uint32_t b, uint32_t c, uint32_t d, int i)
{
	t_md5_utils	ret;

	ret.f = (b & c) | ((~b) & d);
	ret.g = i;
	return (ret);
}

t_md5_utils	func_g(uint32_t b, uint32_t c, uint32_t d, int i)
{
	t_md5_utils	ret;

	ret.f = (d & b) | ((~d) & c);
	ret.g = (5 * i + 1) % 16;
	return (ret);
}

t_md5_utils	func_h(uint32_t b, uint32_t c, uint32_t d, int i)
{
	t_md5_utils	ret;

	ret.f = b ^ c ^ d;
	ret.g = (3 * i + 5) % 16;
	return (ret);
}

t_md5_utils	func_i(uint32_t b, uint32_t c, uint32_t d, int i)
{
	t_md5_utils	ret;

	ret.f = c ^ (b | (~d));
	ret.g = (7 * i) % 16;
	return (ret);
}

t_hash		*set_hash2md5(t_md5 *e)
{
	t_hash	*ret;

	ft_memdel((void**)&e->p.msg8);
	if (!(ret = (t_hash*)malloc(sizeof(t_hash))))
		return (NULL);
	if (!(ret->h = (uint32_t*)malloc(sizeof(uint32_t) * 4)))
		return (NULL);
	ret->nb_word = 4;
	ret->h[0] = e->h0;
	ret->h[1] = e->h1;
	ret->h[2] = e->h2;
	ret->h[3] = e->h3;
	ft_memdel((void**)&(e->p.msg8));
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:40:50 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/22 09:25:33 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/sha256.h"

char	*set_hash2sha256(t_sha256 *e)
{
	t_hash	*ret;
	char	*sum;

	ft_memdel((void**)&(e->p.msg8));
	if (!(ret = (t_hash*)malloc(sizeof(t_hash))))
		ft_abort("Malloc Failed: sha256_utils.c:19:set_hash2sha256()");
	if (!(ret->h = (uint32_t*)ft_memalloc(sizeof(uint32_t) * 8)))
		ft_abort("Malloc Failed: sha256_utils.c:set_hash2sha256()");
	ret->nb_word = 8;
	ret->h[0] = swap_uint32t(e->h0);
	ret->h[1] = swap_uint32t(e->h1);
	ret->h[2] = swap_uint32t(e->h2);
	ret->h[3] = swap_uint32t(e->h3);
	ret->h[4] = swap_uint32t(e->h4);
	ret->h[5] = swap_uint32t(e->h5);
	ret->h[6] = swap_uint32t(e->h6);
	ret->h[7] = swap_uint32t(e->h7);
	sum = hex2sum(ret->h, ret->nb_word);
	ft_memdel((void**)&ret);
	return (sum);
}

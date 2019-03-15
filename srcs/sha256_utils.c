/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:40:50 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/15 11:54:44 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha_2.h"

t_hash	*set_hash2sha256(t_sha256 *e)
{
	t_hash	*ret;

	ft_memdel((void**)&e->p.str_bits);
	ft_memdel((void**)&e->w);
	if (!(ret = (t_hash*)malloc(sizeof(t_hash))))
	{
		ft_memdel((void**)&ret);
		ft_abort("Malloc Failed: sha256_utils.c:19:set_hash2sha256()");
	}
	if (!(ret->h = (uint32_t*)ft_memalloc(sizeof(uint32_t) * 8)))
	{
		ft_memdel((void**)&ret->h);
		ft_abort("Malloc Failed: sha256_utils.c:set_hash2sha256()");
	}
	ret->nb_word = 8;
	ret->h[0] = e->h0;
	ret->h[1] = e->h1;
	ret->h[2] = e->h2;
	ret->h[3] = e->h3;
	ret->h[4] = e->h4;
	ret->h[5] = e->h5;
	ret->h[6] = e->h6;
	ret->h[7] = e->h7;
	return (ret);
}

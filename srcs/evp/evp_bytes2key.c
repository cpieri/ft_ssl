/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evp_bytes2key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:10:42 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/04 11:51:26 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evp/evp_bytes2key.h"
#include <stdio.h>

static void		*evp_loop(t_evp *k, uint32_t c, t_evp_hash hash_f)
{
	size_t	i;
	size_t	data_len;
	t_hash	*digest;
	char	*tmp;
	char	*data;
	char	*ret;
	char	**blocks;

	i = 0;
	data = ft_memjoin(k->pass, k->salt, k->pass_len, k->salt_len);
	data_len = k->pass_len + k->salt_len;
	if (!(blocks = (char**)ft_memalloc(sizeof(char*) * c)))
		return (NULL);
	while (i < c)
	{
		if (i == 0) {
			tmp = data;
			digest = hash_f.f(tmp, data_len);
		}
		else {
			tmp = ft_memjoin(blocks[i - 1], data, hash_f.nb_word, data_len);
			digest = hash_f.f(tmp, hash_f.nb_word + data_len);
			ft_memdel((void**)&tmp);
		}
		blocks[i] = one_sum(digest->h, digest->nb_word);
		ft_memdel((void**)&(digest->h));
		ft_memdel((void**)&digest);
		i++;
	}
	ret = ft_memdup(blocks[c - 1], hash_f.nb_word);
	while (--i > 0)
		ft_memdel((void**)&(blocks[i]));
	ft_memdel((void**)blocks);
	ft_memdel((void**)&data);
	return (ret);
}

void	*evp_bytes2key(t_evp *k, uint32_t c, size_t dk_len, enum e_hash_f func)
{
	t_evp_hash	hash_f;
	void		*tmp;
	char		*ret;

	hash_f = evp_get_hashf(func);
	if (!(ret = (char*)ft_memalloc(sizeof(char) * (dk_len + 1))))
		return (NULL);
	tmp = evp_loop(k, c, hash_f);
	ft_memcpy(ret, tmp, dk_len);
	k->key = ret;
	k->dk_len = dk_len;
	return (ret);
}
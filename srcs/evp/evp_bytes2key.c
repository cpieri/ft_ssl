/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evp_bytes2key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:10:42 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/03 11:15:55 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evp/pbkdf.h"
#include <stdio.h>

static void		*evp_loop(t_pbkdf *k, uint32_t c, t_prf prf)
{
	size_t	i;
	size_t	data_len;
	char	*data;
	char	*ret;
	char	**blocks;

	i = 1;
	data = ft_memjoin(k->pass, k->salt, k->pass_len, k->salt_len);
	data_len = k->pass_len + k->salt_len;
	if (!(blocks = (char**)ft_memalloc(sizeof(char*) * c)))
		return (NULL);
	blocks[0] = (char*)ft_memalloc(sizeof(uint8_t) * prf.nb_word + 1);
	while (i < c)
	{
		blocks[i] = prf.f(data, data_len, blocks[i - 1], prf.nb_word);
		// blocks[i] = prf.f(blocks[i - 1], prf.nb_word, data, data_len);
		i++;
	}
	ret = ft_memdup(blocks[i - 1], prf.nb_word);
	while (--i > 0)
		ft_memdel((void**)&(blocks[i]));
	ft_memdel((void**)blocks);
	ft_memdel((void**)&data);
	return (ret);
}

void	*evp_bytes2key(t_pbkdf *k, uint32_t c, size_t dk_len, enum e_prf func)
{
	t_prf		prf;
	void		*tmp;
	char		*ret;

	if (!(ret = (char*)ft_memalloc(sizeof(char) * (dk_len + 1))))
		return (NULL);
	prf = evp_get_prf(func);
	tmp = evp_loop(k, c, prf);
	ft_memcpy(ret, tmp, dk_len);
	k->key = ret;
	k->dk_len = dk_len;
	return (ret);
}
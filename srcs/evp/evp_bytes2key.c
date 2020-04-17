/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evp_bytes2key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:10:42 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/17 14:06:29 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/symmetric.h"
#include "evp/evp_bytes2key.h"
#include <stdio.h>

static void		*evp_loop(t_evp *k, size_t i, char *key, t_evp_hash hash_f)
{
	char	*data;
	char	*tmp;
	void	*ret;
	t_hash	*digest;
	size_t	len;

	data = ft_memjoin(k->pass, k->salt, k->pass_len, k->salt_len);
	len = k->pass_len + k->salt_len;
	tmp = data;
	if (i != 1)
	{
		tmp = ft_memjoin(key, data, (hash_f.nb_word * (i - 1)), len);
		len += (hash_f.nb_word * (i - 1));
	}
	digest = hash_f.f(tmp, len);
	ret = one_sum(digest->h, digest->nb_word);
	if (len > (k->pass_len + k->salt_len))
		ft_memdel((void**)&tmp);
	ft_memdel((void**)&data);
	ft_memdel((void**)&(digest->h));
	ft_memdel((void**)&digest);
	return (ret);
}

void			*evp_bytes2key(t_evp *k, uint32_t c, t_evp_size full_size, int func)
{
	size_t		i;
	size_t		l;
	t_evp_hash	hash_f;
	void		*tmp;
	char		*ret;

	i = 1;
	(void)c;
	hash_f = evp_get_hashf(func);
	l = ceil((double)(full_size.dk_len / hash_f.nb_word)) + 1;
	if (!(ret = (char*)ft_memalloc(sizeof(char) * (full_size.dk_len + 1))))
		return (NULL);
	while (i <= l)
	{
		tmp = evp_loop(k, i, ret, hash_f);
		ft_memcpy(ret + ((i - 1) * hash_f.nb_word), tmp,
				(i == l) ? full_size.dk_len % hash_f.nb_word : hash_f.nb_word);
		ft_memdel(&tmp);
		i++;
	}
	k->key = ret;
	k->dk_len = full_size.key_len;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:29:58 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/03 10:46:23 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/hmac.h"
#include "hash/md5.h"
#include <stdio.h>

static void	*hmac_md5_digest(void *c1, void *c2, size_t l_c1, size_t l_c2)
{
	void	*data_2_hash;
	size_t	new_len;
	t_hash	*digest;
	char	*char_digest;

	data_2_hash = ft_memjoin(c1, c2, l_c1, l_c2);
	new_len = l_c1 + l_c2;
	digest = (t_hash*)md5(data_2_hash, new_len);
	ft_memdel(&data_2_hash);
	char_digest = one_sum(digest->h, digest->nb_word);
	ft_memdel((void**)&(digest->h));
	ft_memdel((void**)&digest);
	return (char_digest);
}

void		*hmac_md5(void *data, size_t data_len, void *key, size_t key_len)
{
	void	*digest;
	void	*tmp_digest;
	void	*new_key;
	void	*i_key_pad;
	void	*o_key_pad;

	if (key_len > HMAC_BLOCK_SIZE_512)
	{
		new_key = hmac_md5_digest(key, NULL, key_len, 0);
		key_len = 16;
	}
	else if (key_len < HMAC_BLOCK_SIZE_512)
		if (!(new_key = hmac_512_padding_key(key, &key_len)))
			return (NULL);
	i_key_pad = hmac_512_xor_ipad(new_key, key_len);
	o_key_pad = hmac_512_xor_opad(new_key, key_len);
	tmp_digest = hmac_md5_digest(i_key_pad, data, key_len, data_len);
	ft_memdel(&i_key_pad);
	digest = hmac_md5_digest(o_key_pad, tmp_digest, key_len, 16);
	ft_memdel(&tmp_digest);
	ft_memdel(&o_key_pad);
	ft_memdel(&new_key);
	return (digest);
}

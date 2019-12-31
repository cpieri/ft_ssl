/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_sha1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 08:16:56 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/31 12:23:27 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/hmac.h"
#include "hash/sha1.h"

static void	*hmac_sha1_digest(void *c1, void *c2, size_t len_c1, size_t len_c2)
{
	void	*data_2_hash;
	size_t	new_len;
	t_hash	*digest;
	char	*char_digest;

	data_2_hash = ft_memjoin(c1, c2, len_c1, len_c2);
	new_len = len_c1 + len_c2;
	digest = (t_hash*)sha1(data_2_hash, new_len);
	ft_memdel(&data_2_hash);
	char_digest = one_sum(digest->h, digest->nb_word);
	ft_memdel((void**)&(digest->h));
	ft_memdel((void**)&digest);
	return (char_digest);
}

void		*hmac_sha1(void *data, size_t data_len, void *key, size_t key_len)
{
	void	*digest;
	void	*tmp_digest;
	void	*new_key;
	void	*i_key_pad;
	void	*o_key_pad;

	if (key_len > HMAC_BLOCK_SIZE_512)
	{
		new_key = hmac_sha1_digest(key, NULL, key_len, 0);
		key_len = 20;
	}
	else if (key_len < HMAC_BLOCK_SIZE_512)
		if (!(new_key = hmac_512_padding_key(key, &key_len)))
			return (NULL);
	i_key_pad = hmac_512_xor_ipad(new_key, key_len);
	o_key_pad = hmac_512_xor_opad(new_key, key_len);
	tmp_digest = hmac_sha1_digest(i_key_pad, data, key_len, data_len);
	ft_memdel(&i_key_pad);
	digest = hmac_sha1_digest(o_key_pad, tmp_digest, key_len, 20);
	ft_memdel(&tmp_digest);
	ft_memdel(&o_key_pad);
	ft_memdel(&new_key);
	return (digest);
}

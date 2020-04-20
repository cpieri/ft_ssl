/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:22:16 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/31 12:24:41 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/hmac.h"

void	*hmac_512_padding_key(void *key, size_t *key_len)
{
	uint8_t	*new_key;
	size_t	size;

	size = HMAC_BLOCK_SIZE_512 * sizeof(uint8_t);
	if (!(new_key = (uint8_t*)ft_memalloc(size)))
		return (NULL);
	new_key = ft_memcpy(new_key, key, *key_len);
	*key_len = HMAC_BLOCK_SIZE_512;
	return (new_key);
}

void	*hmac_512_xor_ipad(void const *key, size_t key_len)
{
	char	*i_pad;
	char	*key_cpy;
	size_t	i;

	key_cpy = (char*)key;
	if (!(i_pad = (char*)ft_memalloc(key_len * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < HMAC_BLOCK_SIZE_512)
		i_pad[i] = key_cpy[i] ^ I_PAD;
	return (i_pad);
}

void	*hmac_512_xor_opad(void const *key, size_t key_len)
{
	char	*o_pad;
	char	*key_cpy;
	size_t	i;

	key_cpy = (char*)key;
	if (!(o_pad = (char*)ft_memalloc(key_len * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < HMAC_BLOCK_SIZE_512)
		o_pad[i] = key_cpy[i] ^ O_PAD;
	return (o_pad);
}

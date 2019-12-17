/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:28:18 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/17 11:40:18 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/pbkdf.h"

void	hmac_sha256(uint8_t *pass, uint64_t salt, uint32_t c)
{
	void	*data_to_hash;
	void	*salty_pass;
	size_t	salty_pass_len;
	size_t	hash_len;
	char	*sum[c];
	t_hash	*hash;
	uint32_t	i;

	// ft_putstr("Pass :"); ft_putstr((char*)pass); ft_putstr("\n");
	salty_pass = ft_memjoin(pass, &salt, ft_strlen((char*)pass), sizeof(uint64_t));
	salty_pass_len = ft_strlen((char*)pass) + sizeof(uint64_t);
	// ft_putstr("Salty Pass :"); ft_memput(salty_pass, salty_pass_len); ft_putstr("\n");
	data_to_hash = ft_memjoin(salty_pass, &c, salty_pass_len, sizeof(uint32_t));
	hash_len = salty_pass_len + sizeof(uint32_t);
	// ft_putstr("Data to hash :"); ft_memput(data_to_hash, hash_len); ft_putstr("\n");
	hash = (t_hash*)sha256(data_to_hash, hash_len);
	sum[0] = one_sum(hash->h, hash->nb_word);
	ft_memdel((void**)&data_to_hash);
	ft_memdel((void**)&salty_pass);
	data_to_hash = ft_memjoin(pass, sum[0], ft_strlen((char*)pass), (hash->nb_word * sizeof(uint32_t)));
	ft_memdel((void**)&(hash->nb_word));
	ft_memdel((void**)&hash);
	i = 0;
	while (i <= c)
	{
		hash = (t_hash*)sha256(data_to_hash, hash_len);
		sum[i] = one_sum(hash->h, hash->nb_word);
	}

	// ft_memput(data_to_hash, salty_pass_len + sizeof(uint32_t));
}
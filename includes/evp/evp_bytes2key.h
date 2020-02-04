/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evp_bytes2key.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:03:30 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/04 14:38:46 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVP_BYTES2KEY_H
# define EVP_BYTES2KEY_H

# include "./evp.h"
# include "../hash/md5.h"
# include "../hash/sha1.h"
# include "../hash/sha256.h"

enum			e_hash_f
{
	EVP_MD5 = 0x000000001,
	EVP_SHA1 = 0x000000010,
	EVP_SHA256 = 0x000000100
};

typedef struct			s_evp_hash
{
	enum e_hash_f		hash_f;
	void				*(*f)(void *, size_t);
	size_t				nb_word;
}						t_evp_hash;

t_evp_hash				evp_get_hashf(enum e_hash_f name);
void					*evp_bytes2key(t_evp *k, uint32_t c, size_t dk_len,
			enum e_hash_f func);

#endif
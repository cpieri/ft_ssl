/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:11:40 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/04 10:06:24 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBKDF_H
# define PBKDF_H

# include "./evp.h"
# include "../hash/hmac.h"

enum			e_prf
{
	HMAC_MD5 = 0x000000001,
	HMAC_SHA1 = 0x000000010,
	HMAC_SHA256 = 0x000000100
};

typedef struct	s_prf
{
	enum e_prf	prf;
	void		*(*f)(void *, size_t, void *, size_t);
	size_t		nb_word;
}				t_prf;

t_prf			pbkdf2_get_prf(enum e_prf name);
void			pbkdf2_xor_dgst(void const *dgst1, void const *dgst2, size_t nb);
void			*pbkdf2(t_evp *k, uint32_t c, size_t dk_len, enum e_prf func);

#endif

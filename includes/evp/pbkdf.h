/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:11:40 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/03 09:27:47 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBKDF_H
# define PBKDF_H

# include "../../libft/include/libft.h"
# include "../hash/hmac.h"
# include "../functions.h"
# include "../structure.h"

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

typedef struct	s_pbkdf
{
	void		*pass;
	void		*salt;
	void		*key;
	size_t		pass_len;
	size_t		salt_len;
	size_t		dk_len;
	uint64_t	vect;
}				t_pbkdf;


/*
**	EVP Functions utils
*/
t_prf			evp_get_prf(enum e_prf name);

/*
**	Functions for create and del struct symmetric key
*/
void			*pbkdf2(t_pbkdf *k, uint32_t c, size_t dk_len, enum e_prf func);
t_pbkdf			*new_t_pbkdf(uint8_t *pass, void *salt, uint64_t key,
			uint64_t vect);
void			print_pbkdf(t_pbkdf *to_print);
void			free_pbkdf(t_pbkdf **to_free);
void			free_vpbkdf(void **to_free);
uint64_t		gen_key(uint8_t *pass, uint64_t salt);
void			*pbkdf2(t_pbkdf *k, uint32_t c, size_t dk_len, enum e_prf func);
void			*evp_bytes2key(t_pbkdf *k, uint32_t c, size_t dk_len,
			enum e_prf func);
void			regen_key(t_pbkdf **k);

#endif

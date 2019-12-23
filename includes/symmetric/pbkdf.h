/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:11:40 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/23 15:51:00 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBKDF_H
# define PBKDF_H

# include "../../libft/include/libft.h"
# include "../hash/sha256.h"
# include "../hash/md5.h"
# include "../functions.h"
# include "../structure.h"

enum			e_prf
{
	HMAC_MD5 = 0x000000001,
	HMAC_SHA256 = 0x000000010
};

typedef struct	s_prf
{
	enum e_prf	prf;
	void		*(*f)(uint8_t *, uint64_t, uint32_t);
}				t_prf;

typedef struct	s_pbkdf
{
	uint8_t		*pass;
	uint64_t	salt;
	uint64_t	key;
	uint64_t	vect;
}				t_pbkdf;

/*
**	Functions for create and del struct symmetric key
*/
uint8_t			*get_pass(const char *prompt);
t_pbkdf			*new_key(uint8_t *pass, uint64_t salt, uint64_t key,
				uint64_t vect);
void			print_pbkdf(t_pbkdf *to_print);
void			free_pbkdf(t_pbkdf **to_free);
void			free_vpbkdf(void **to_free);
uint64_t		gen_key(uint8_t *pass, uint64_t salt);
uint64_t		ft_pbkdf2(uint8_t *pass, uint64_t salt);
void			regen_key(t_pbkdf **k);

#endif

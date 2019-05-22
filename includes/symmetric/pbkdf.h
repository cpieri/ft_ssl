/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:11:40 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/22 10:50:10 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBKDF_H
# define PBKDF_H

# include "../../libft/include/libft.h"
# include "../hash/sha256.h"
# include "../hash/md5.h"
# include "../functions.h"
# include "../structure.h"

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
void			regen_key(t_pbkdf **k);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:13:54 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/04 09:56:20 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVP_H
# define EVP_H

# include "../../libft/include/libft.h"
# include "../structure.h"
# include "../functions.h"
# include "../hash/hash.h"

typedef struct	s_evp
{
	void		*pass;
	void		*salt;
	void		*key;
	size_t		pass_len;
	size_t		salt_len;
	size_t		dk_len;
	uint64_t	vect;
}				t_evp;

t_evp			*new_t_evp(uint8_t *pass, void *salt, uint64_t key,
			uint64_t vect);
void			print_evp(t_evp *to_print);
void			free_evp(t_evp **to_free);
void			free_vevp(void **to_free);

#endif
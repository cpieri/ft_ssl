/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:10:43 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/20 12:30:28 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/pbkdf.h"

uint64_t	gen_key(uint8_t *pass, uint64_t salt)
{
	uint64_t	new_key;
	uint8_t		*tmp_pass;
	t_hash		*shasum256_pass;
	size_t		len_pass;
	int			ismalloc;

	new_key = 0;
	len_pass = ft_strlen((char *)pass);
	tmp_pass = pass;
	ismalloc = 0;
	if (salt > 0)
	{
		tmp_pass = ft_memjoin(pass, &salt, len_pass, sizeof(uint64_t));
		len_pass += sizeof(uint64_t);
		ismalloc = 1;
	}
	shasum256_pass = sha256(tmp_pass, len_pass);
	new_key = (shasum256_pass->h[0]);
	new_key = new_key << 32 | (shasum256_pass->h[1]);
	ft_memdel((void**)&(shasum256_pass->h));
	ft_memdel((void**)&(shasum256_pass));
	if (ismalloc == 1)
		ft_memdel((void**)&(tmp_pass));
	return (new_key);
}

t_pbkdf		*new_key(uint8_t *pass, uint64_t salt, uint64_t key, uint64_t vect)
{
	t_pbkdf	*new;

	if (!(new = (t_pbkdf*)malloc(sizeof(t_pbkdf))))
		return (NULL);
	new->pass = pass;
	new->salt = (salt > 0) ? salt : get_random();
	new->key = (key > 0) ? key : gen_key(new->pass, new->salt);
	new->vect = vect;
	return (new);
}

void		regen_key(t_pbkdf **k)
{
	(*k)->key = 0;
	if ((*k)->pass != NULL)
		(*k)->key = gen_key((*k)->pass, (*k)->salt);
}

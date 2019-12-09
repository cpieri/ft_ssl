/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:10:43 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/09 14:29:35 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/pbkdf.h"
#include <stdio.h>

uint64_t	gen_key(uint8_t *pass, uint64_t salt)
{
	uint64_t	new_key;
	uint8_t		*tmp_pass;
	t_hash		*sum;
	size_t		len_pass;
	// int			iter = 1000;
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
	printf("Debug: sizeof(): %zu\n", sizeof(uint32_t));
	sum = sha256(tmp_pass, len_pass);
	for (int i = 1000; i >= 0; i--)
	{
		printf("Debug: i: %d\n", i);
		sum = sha256(sum->h, 32);
		new_key = (sum->h[0]);
		new_key = new_key << 32 | (sum->h[1]);
		printf("Debug: sum: %s\n", hex2sum(sum->h, sum->nb_word));
		printf("Debug: key: %llx\n", new_key);
	}
	// ft_memdel((void**)&(shasum256_pass->h));
	// ft_memdel((void**)&(shasum256_pass));
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
	new->key = (key > 0) ? key : 0;
	new->vect = vect;
	return (new);
}

void		regen_key(t_pbkdf **k)
{
	(*k)->key = 0;
	if ((*k)->pass != NULL)
		(*k)->key = gen_key((*k)->pass, (*k)->salt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:10:43 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/23 15:55:01 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/pbkdf.h"
#include <stdio.h>

static const t_prf	g_prf[3] = {
	{HMAC_MD5, NULL},
	{HMAC_SHA256, hmac_sha256},
	{0, NULL}
};

uint64_t	ft_pbkdf2(uint8_t *pass, uint64_t salt)
{
	uint32_t	counter;
	void		*sum;
	t_prf		prf;

	counter = 1000;
	prf = g_prf[1];
	sum = prf.f(pass, salt, counter);
	// printf("sum: %s\n", hex2sum(sum, 8));
	return (0);
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

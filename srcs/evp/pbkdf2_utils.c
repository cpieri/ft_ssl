/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf2_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 13:31:54 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/03 09:28:07 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evp/pbkdf.h"

static const t_prf	g_prf[4] = {
	{HMAC_MD5, hmac_md5, 16},
	{HMAC_SHA1, hmac_sha1, 20},
	{HMAC_SHA256, hmac_sha256, 32},
	{0, NULL, 0}
};

t_prf		evp_get_prf(enum e_prf name)
{
	t_prf	ret;
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (g_prf[i].prf == name)
			ret = g_prf[i];
		i++;
	}
	return (ret);
}

t_pbkdf		*new_key(uint8_t *pass, void *salt, uint64_t key, uint64_t vect)
{
	t_pbkdf	*new;

	if (!(new = (t_pbkdf*)malloc(sizeof(t_pbkdf))))
		return (NULL);
	new->pass = pass;
	new->pass_len = ft_strlen((char*)new->pass);
	new->salt = (salt != NULL) ? salt : get_random();
	new->salt_len = ft_strlen((char*)new->salt);
	new->key = (key != 0x00) ? &key : 0x00;
	new->vect = vect;
	return (new);
}

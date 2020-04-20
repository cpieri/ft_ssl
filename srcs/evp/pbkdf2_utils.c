/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf2_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 13:31:54 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/20 10:30:49 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evp/pbkdf.h"

static const t_prf	g_prf[4] = {
	{HMAC_MD5, hmac_md5, 16},
	{HMAC_SHA1, hmac_sha1, 20},
	{HMAC_SHA256, hmac_sha256, 32},
	{0, NULL, 0}
};

t_prf		pbkdf2_get_prf(enum e_prf name)
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

void		pbkdf2_xor_dgst(void const *dgst1, void const *dgst2, size_t n)
{
	char	*dgst1_cpy;
	char	*dgst2_cpy;
	size_t	i;

	i = 0;
	dgst1_cpy = (char*)dgst1;
	dgst2_cpy = (char*)dgst2;
	while (i < n)
	{
		dgst1_cpy[i] ^= dgst2_cpy[i];
		i++;
	}
}

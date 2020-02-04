/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evp_b2k_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:11:43 by cpieri            #+#    #+#             */
/*   Updated: 2020/02/04 13:05:03 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evp/evp_bytes2key.h"

static const t_evp_hash		g_evp_hash[4] = {
	{EVP_MD5, md5, 16},
	{EVP_SHA1, sha1, 20},
	{EVP_SHA256, sha256, 32},
	{0, NULL, 0}
};

t_evp_hash		evp_get_hashf(enum e_hash_f name)
{
	t_evp_hash	ret;
	size_t		i;

	i = 0;
	while (i < 4)
	{
		if (g_evp_hash[i].hash_f == name)
			ret = g_evp_hash[i];
		i++;
	}
	return (ret);
}

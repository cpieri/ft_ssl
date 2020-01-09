/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 13:29:35 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/09 13:16:11 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbkdf2/pbkdf.h"
#include <math.h>

static const t_prf	g_prf[4] = {
	{HMAC_MD5, hmac_md5, 16},
	{HMAC_SHA1, hmac_sha1, 20},
	{HMAC_SHA256, hmac_sha256, 32},
	{0, NULL, 0}
};

static t_prf	pbkdf2_get_prf(enum e_prf name)
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

static void		pbkdf2_xor_dgst(void const *dgst1, void const *dgst2, size_t nb)
{
	char	*dgst1_cpy;
	char	*dgst2_cpy;
	size_t	i;

	i = 0;
	dgst1_cpy = (char*)dgst1;
	dgst2_cpy = (char*)dgst2;
	while (i < nb)
	{
		dgst1_cpy[i] ^= dgst2_cpy[i];
		i++;
	}
}

static void		*first_i(t_pbkdf *k, size_t y, t_prf prf)
{
	void	*buff;
	void	*ret;

	if (!(buff = ft_memalloc(k->salt_len + 4)))
		return (NULL);
	ft_memcpy(buff, k->salt, k->salt_len);
	*(uint32_t*)(buff + k->salt_len) = swap_uint32t((uint32_t)y);
	ret = prf.f(buff, k->salt_len + 4, k->pass, k->pass_len);
	ft_memdel(&buff);
	return (ret);
}

static void		*pbkdf2_f(t_pbkdf *k, uint32_t c, t_prf prf, size_t y)
{
	size_t	i;
	char	*ret;
	char	**blocks;

	i = 0;
	if (!(blocks = (char**)ft_memalloc(sizeof(char*) * c)))
		return (NULL);
	while (i < c)
	{
		if (i == 0)
			blocks[0] = first_i(k, y, prf);
		else
		{
			blocks[i] = prf.f(blocks[i - 1], prf.nb_word, k->pass, k->pass_len);
			pbkdf2_xor_dgst(blocks[0], blocks[i], prf.nb_word);
		}
		i++;
	}
	ret = ft_memdup(blocks[0], prf.nb_word);
	while (--i > 0)
		ft_memdel((void**)&(blocks[i]));
	ft_memdel((void**)blocks);
	return (ret);
}

void			*pbkdf2(t_pbkdf *k, uint32_t c, size_t dk_len, enum e_prf func)
{
	size_t		i;
	size_t		l;
	void		*tmp;
	char		*ret;
	t_prf		prf;

	i = 1;
	prf = pbkdf2_get_prf(func);
	l = ceil((double)(dk_len / prf.nb_word)) + 1;
	if (!(ret = (char*)ft_memalloc(sizeof(char) * (dk_len + 1))))
		return (NULL);
	while (i <= l)
	{
		tmp = pbkdf2_f(k, c, prf, i);
		ft_memcpy(ret + ((i - 1) * prf.nb_word), tmp,
				(i == l) ? dk_len % prf.nb_word : prf.nb_word);
		ft_memdel(&tmp);
		i++;
	}
	k->key = ret;
	k->dk_len = dk_len;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 13:29:35 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/17 13:46:08 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/symmetric.h"
#include "evp/pbkdf.h"

static void		*first_i(t_evp *k, size_t y, t_prf prf)
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

static void		*pbkdf2_f(t_evp *k, uint32_t c, t_prf prf, size_t y)
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

void			*pbkdf2(t_evp *k, uint32_t c, t_evp_size full_size, int func)
{
	size_t		i;
	size_t		l;
	void		*tmp;
	char		*ret;
	t_prf		prf;

	i = 1;
	prf = pbkdf2_get_prf(func);
	l = ceil((double)(full_size.dk_len / prf.nb_word)) + 1;
	if (!(ret = (char*)ft_memalloc(sizeof(char) * (full_size.dk_len + 1))))
		return (NULL);
	while (i <= l)
	{
		tmp = pbkdf2_f(k, c, prf, i);
		ft_memcpy(ret + ((i - 1) * prf.nb_word), tmp,
				(i == l) ? full_size.dk_len % prf.nb_word : prf.nb_word);
		ft_memdel(&tmp);
		i++;
	}
	k->key = ret;
	k->dk_len = full_size.key_len;
	return (ret);
}

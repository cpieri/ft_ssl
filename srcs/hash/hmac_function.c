/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:28:18 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/23 16:58:11 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/pbkdf.h"
#include <stdio.h>

static void		*hmac_xor_u(void const *u1, void const *u2, size_t len, size_t size)
{
	char	*u1_cpy;
	char	*u2_cpy;
	char	*u;
	size_t	i;

	u1_cpy = (char*)u1;
	u2_cpy = (char*)u2;
	i = 0;
	if (!(u = (char*)ft_memalloc(len * size)))
		return (NULL);
	while (i < (len * size))
	{
		u[i] = u1_cpy[i] ^ u2_cpy[i];
		// ft_putbits(u1_cpy[i]); ft_putchar(' ');
		// ft_putbits(u2_cpy[i]); ft_putchar(' '); ft_putchar('='); ft_putchar(' ');
		// ft_putbits(u[i]); ft_putchar('\n');
		i++;
	}
	return (u);
}

static void		*hmac_sha256_i(void *data, size_t data_len)
{
	t_hash	*hash;
	void	*sum;

	hash = (t_hash*)sha256(data, data_len);
	sum = one_sum(hash->h, hash->nb_word);
	ft_memdel((void**)&(hash->h));
	ft_memdel((void**)&hash);
	return (sum);
}

void	*hmac_sha256(uint8_t *pass, uint64_t salt, uint32_t c)
{
	void	*data_to_hash;
	void	*salty_pass;
	size_t	salty_pass_len;
	size_t	hash_len;
	void	*sum[c];
	void	*f_sum = NULL;
	void	*tmp;
	uint32_t	i;

	salty_pass = ft_memjoin(pass, &salt, ft_strlen((char*)pass), sizeof(uint64_t));
	salty_pass_len = ft_strlen((char*)pass) + sizeof(uint64_t);

	data_to_hash = ft_memjoin(salty_pass, &c, salty_pass_len, sizeof(uint32_t));
	hash_len = salty_pass_len + sizeof(uint32_t);
	sum[0] = hmac_sha256_i(data_to_hash, hash_len);
	printf("%d: %s\n", 0, hex2sum(sum[0], 8));

	data_to_hash = ft_memjoin(pass, sum[0], ft_strlen((char*)pass), (8 * sizeof(uint32_t)));
	sum[1] = hmac_sha256_i(data_to_hash, hash_len);
	f_sum = hmac_xor_u(sum[0], sum[1], 8, sizeof(uint32_t));
	printf("%d: %s\n", 1, hex2sum(f_sum, 8));

	data_to_hash = ft_memjoin(pass, sum[1], ft_strlen((char*)pass), (8 * sizeof(uint32_t)));
	i = 1;
	while (++i <= c)
	{
		sum[i] = hmac_sha256_i(data_to_hash, hash_len);
		data_to_hash = ft_memjoin(pass, sum[i], ft_strlen((char*)pass), (8 * sizeof(uint32_t)));
		tmp = hmac_xor_u(f_sum, sum[i], 8, sizeof(uint32_t));
		ft_memdel((void**)&f_sum);
		f_sum = tmp;
		printf("%d: %s\n", i, hex2sum(f_sum, 8));
	}
	// while (1);
	// ft_putstr("sum: "), ft_membits(f_sum, hash->nb_word, sizeof(uint32_t));
	return (f_sum);
	// ft_memput(data_to_hash, salty_pass_len + sizeof(uint32_t));
}
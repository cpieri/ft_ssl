/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:05:42 by cpieri            #+#    #+#             */
/*   Updated: 2020/05/05 12:22:48 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/des/des.h"
#include "symmetric/symmetric.h"

static const int	g_des_ip[64] = {
	58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46,
	38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9,
	1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47,
	39, 31, 23, 15, 7
};

static const int	g_des_cycle[48] = {
	32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15,
	16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28,
	29, 28, 29, 30, 31, 32, 1
};

static void		des_cycle(uint8_t *block, size_t len_block, void *key, int dk_l)
{
	uint32_t	part_1;
	uint32_t	part_2;
	uint32_t	*key_32;
	int			i;
	uint8_t		*permute;

	(void)(len_block);
	i = 0;
	part_1 = ((uint32_t*)block)[0];
	part_2 = ((uint32_t*)block)[1];
	while (i < 16)
	{
		permute = des_permute(((uint8_t*)(&part_2)), g_des_cycle, 48);
		key_32 = des_key_schedule_32(key, dk_l, i);
		i++;
	}
}

void			*des(void *opt, size_t len_opt)
{
	t_data		*data;
	uint8_t		*block_permuted;
	size_t		offest;
	// t_evp	*evp_data;

	(void)len_opt;
	offest = 0;
	data = ((t_opt*)opt)->data;
	while (offest < data->len_data)
	{
		block_permuted = des_permute((uint8_t*)(data + offest), g_des_ip, 64);
		des_cycle(block_permuted, 8, ((t_evp*)data->pass)->key, ((t_evp*)data->pass)->dk_len);
		offest += 8;
	}
	return (opt);
}
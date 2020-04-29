/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:05:42 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/29 13:48:52 by cpieri           ###   ########.fr       */
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

static void		des_cycle(uint8_t *block, size_t len_block)
{
	uint32_t	part_1;
	uint32_t	part_2;
	uint8_t		*permute;

	(void)(len_block);
	part_1 = ((uint32_t*)block)[0];
	part_2 = ((uint32_t*)block)[1];
	permute = des_permute(((uint8_t*)(&part_2)), g_des_cycle, 48);
}

void			*des(void *opt, size_t len_opt)
{
	t_opt	*opt_cpy;
	char	*data;
	uint8_t	*block_permuted;
	size_t	len_data;
	size_t	offest;
	// t_evp	*evp_data;

	(void)len_opt;
	offest = 0;
	opt_cpy = opt;
	data = opt_cpy->data->data;
	len_data = opt_cpy->data->len_data;
	while (offest < len_data)
	{
		block_permuted = des_permute((uint8_t*)(data + offest), g_des_ip, 64);
		des_cycle(block_permuted, 8);
		offest += 8;
	}
	// evp_data = opt_cpy->data->pass;
	// des_key_schedule(evp_data->key, evp_data->dk_len);
	// Code
	return (opt);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:05:42 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/27 17:16:45 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/des/des.h"
#include "symmetric/symmetric.h"

static const uint8_t	g_des_ip[64] = {
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7,
};

static uint8_t	*permute_block(uint8_t *block, size_t len_block)
{
	uint8_t		*result;
	int			i;

	i = 0;
	if (!(result = (uint8_t*)ft_memalloc(sizeof(uint8_t) * 8)))
		return (NULL);
	while (i < 64)
	{
		if ((block[(g_des_ip[i] - 1) / 8] >> (7 - ((g_des_ip[i] - 1) % 8))) & 1)
			result[i  / 8] |= (1 << (7 - (i % 8)));
		i++;
	}
	return (result);
}

void			*des(void *opt, size_t len_opt)
{
	t_opt	*opt_cpy;
	char	*data;
	char	*block_permuted;
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
		block_permuted = permute_block((uint8_t*)(data + offest), 8);
		offest += 8;
	}
	// evp_data = opt_cpy->data->pass;
	// des_key_schedule(evp_data->key, evp_data->dk_len);
	// Code
	return (opt);
}
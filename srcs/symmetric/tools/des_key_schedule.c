/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_key_schedule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:08:06 by cpieri            #+#    #+#             */
/*   Updated: 2020/05/04 15:46:50 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/des/des.h"

static const int	g_des_key_r[28] = {
	63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37,
	29, 21, 13, 5, 28, 20, 12, 4
};

static const int	g_des_key_l[28] = {
	57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35,
	27, 19, 11, 3, 60, 52, 44, 36
};

static const int	g_des_key_left_shift[16] = {
	1, 2, 4, 6, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28
};

static const int	g_des_key_32[32] = {
	14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27,
	20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56,
	34, 53, 46, 42, 50, 36, 29, 32
};

t_des_key	des_key_schedule(void *key, size_t key_len, int i)
{
	t_des_key	keys;
	uint32_t	left_tmp;
	uint32_t	right_tmp;
	int			nb;

	(void)key_len;
	nb = g_des_key_left_shift[i];
	keys.key_left = des_permute(key, g_des_key_l, 28);
	keys.key_right = des_permute(key, g_des_key_r, 28);
	left_tmp = left_shift(((uint32_t*)keys.key_left)[0], nb);
	right_tmp = left_shift(((uint32_t*)keys.key_right)[0], nb);
	
	return (keys);
}
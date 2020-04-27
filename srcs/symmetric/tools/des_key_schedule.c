/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_key_schedule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:08:06 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/24 17:07:12 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/des/des.h"

void	des_key_schedule(void *key, size_t key_len)
{
	// uint32_t	part_1;
	// uint32_t	part_2;
	// uint32_t	tmp;
	size_t	i;
	uint8_t	*key_cpy;

	i = 0;
	key_cpy = (uint8_t*)key;
	ft_membits(key_cpy, 8, sizeof(uint8_t));
	while (i < key_len)
	{
		ft_membits(&key_cpy[i], 1, sizeof(uint8_t));
		i++;
	}

}
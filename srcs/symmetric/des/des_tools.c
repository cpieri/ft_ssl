/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 11:38:58 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/29 11:50:26 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/des/des.h"

uint8_t		*des_permute(uint8_t *to_perm, const int *arr, size_t new_len)
{
	uint8_t		*result;
	size_t		i;

	i = 0;
	if (!(result = (uint8_t*)ft_memalloc(sizeof(uint8_t) * (new_len / 8))))
		return (NULL);
	while (i < new_len)
	{
		if ((to_perm[(arr[i] - 1) / 8] >> (7 - ((arr[i] - 1) % 8))) & 1)
			result[i  / 8] |= (1 << (7 - (i % 8)));
		i++;
	}
	return (result);
}
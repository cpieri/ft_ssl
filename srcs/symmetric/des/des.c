/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:05:42 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/06 11:27:13 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/des/des.h"
#include "symmetric/symmetric.h"

void	*des(void *msg, size_t len)
{
	void	*key;
	size_t	len_key;

	(void)len;
	len_key = 0;
	key = gen_random_key(&len_key);
	ecb(msg, key, len, len_key);
	return (msg);
}
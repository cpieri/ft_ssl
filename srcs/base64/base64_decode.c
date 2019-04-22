/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_decode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:41:31 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/22 09:53:34 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64/base64.h"
#include <stdio.h>

static size_t	b64_len_decode(uint8_t *s)
{
	size_t	new_len;
	uint8_t	*tmp;

	tmp = s;
	while (g_base64_d[*(tmp++)] <= 63);
	new_len = (tmp - s) - 1;
	printf("new_len = %zu\n", new_len);
	return (((new_len + 3) / 4) * 3);
}

uint8_t			*base64_decode(uint8_t *msg, size_t len)
{
	size_t	len_plain;

	(void)len;
	printf("decode func\n");
	len_plain = b64_len_decode(msg);
	printf("len_plain = %zu\n", len_plain);
	return (msg);
}

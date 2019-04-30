/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_decode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:41:31 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/30 15:47:31 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64/base64.h"
#include <stdio.h>

static const unsigned char g_base64_d[] = {
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63, 52, 53, 54, 55, 56, 57,
	58, 59, 60, 61, 64, 64, 64, 65, 64, 64, 64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64,
	64, 64, 64, 64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
	40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64
};

static size_t	b64_decode_len(uint8_t *msg, size_t len)
{
	size_t	i;
	size_t	soft_len;
	size_t	new_len;

	soft_len = 0;
	i = -1;
	while (++i < len)
		if (!ft_isspace(msg[i]))
			soft_len++;
	new_len = (soft_len / 4) * 3;
	len -= (ft_isspace(msg[len - 1])) ? 2 : 1;
	while (msg[len--] == '=')
		new_len--;
	return (new_len);
}

static uint32_t	b64_decode_val(uint8_t *msg, size_t *i)
{
	uint32_t	tmp;
	uint16_t	l_shift;
	size_t		j;
	size_t		p;

	j = *i;
	p = 0;
	l_shift = 18;
	tmp = 0;
	while (p < 4)
	{
		if (!ft_isspace(msg[j]))
		{
			tmp += g_base64_d[msg[j]] << l_shift;
			l_shift += (l_shift == 0) ? 18 : -6;
			p++;
		}
		j++;
	}
	*i = j;
	return (tmp);
}

static void		b64_decode_end(uint8_t *msg_d, uint8_t *msg, int len, int j)
{
	msg_d += j;
	if ((j + 1) < len)
		*msg_d++ = (g_base64_d[*msg] << 2 | g_base64_d[*(msg + 1)] >> 4);
	if ((j + 2) < len)
		*msg_d++ = (g_base64_d[*(msg + 1)] << 4 | g_base64_d[*(msg + 2)] >> 2);
	if ((j + 3) < len)
		*msg_d++ = (g_base64_d[*(msg + 2)] << 6 | g_base64_d[*(msg + 3)]);
}

uint8_t			*base64_decode(uint8_t *msg, size_t len)
{
	uint8_t		*msg_d;
	uint32_t	tmp;
	size_t		len_plain;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	tmp = 0;
	len_plain = b64_decode_len(msg, len);
	if (!(msg_d = (uint8_t*)ft_memalloc(sizeof(uint8_t) * len_plain)))
		return (NULL);
	while ((j + 3) <= len_plain)
	{
		tmp = b64_decode_val(msg, &i);
		msg_d[j++] = (tmp >> 16) & 0xff;
		msg_d[j++] = (tmp >> 8) & 0xff;
		msg_d[j++] = tmp & 0xff;
	}
	b64_decode_end(msg_d, msg + i, len_plain, j);
	return (msg_d);
}

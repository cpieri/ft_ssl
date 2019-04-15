/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:29:50 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/15 13:41:51 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64/base64.h"

static size_t	b64_len_encode(size_t len)
{
	return (((len + 2) / 3 * 4) + 1);
}

static void		b64_encode_value(t_base64_encode *n, uint8_t *msg, size_t i)
{
	n->n0 = ((msg[i] >> 2) & 0x3f);
	n->n1 = ((((msg[i] & 0x3) << 4) | ((msg[i + 1] & 0xf0) >> 4))) & 0x3f;
	n->n2 = (((msg[i + 1] & 0xf) << 2) | ((msg[i + 2] & 0xc0) >> 6)) & 0x3f;
	n->n3 = ((msg[i + 2]) & 0x3f);
}

static void		b64_encode_padding(uint8_t *new_s, uint8_t *msg, size_t i,
	size_t len)
{
	uint8_t		n;

	if (i < len)
	{
		*new_s++ = g_base64_c[((msg[i] >> 2) & 0x3f)];
		if (i == (len - 1))
		{
			*new_s++ = g_base64_c[((msg[i] & 0x3) << 4)];
			*new_s++ = '=';
		}
		else
		{
			n = ((((msg[i] & 0x3) << 4) | ((msg[i + 1] & 0xf0) >> 4))) & 0x3f;
			*new_s++ = g_base64_c[n];
			*new_s++ = g_base64_c[((msg[i + 1] & 0xf) << 2)];
		}
		*new_s++ = '=';
	}
}

uint8_t			*base64_encode(uint8_t *msg, size_t len)
{
	size_t			i;
	uint8_t			*new_s;
	uint8_t			*tmp;
	t_base64_encode	n;

	i = 0;
	n = (t_base64_encode){0, 0, 0, 0};
	if (!(new_s = (uint8_t*)ft_memalloc(sizeof(uint8_t) * b64_len_encode(len))))
		return (NULL);
	tmp = new_s;
	while (i < (len - 2))
	{
		b64_encode_value(&n, msg, i);
		*tmp++ = g_base64_c[n.n0];
		*tmp++ = g_base64_c[n.n1];
		*tmp++ = g_base64_c[n.n2];
		*tmp++ = g_base64_c[n.n3];
		i += 3;
	}
	b64_encode_padding(tmp, msg, i, len);
	return (new_s);
}

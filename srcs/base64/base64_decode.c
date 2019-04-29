/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_decode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:41:31 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/29 19:23:03 by cpieri           ###   ########.fr       */
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
	size_t	new_len;

	new_len = (len / 4) * 3;
	len -= 2;
	// printf("msg[len]: %c\n", msg[len]);
	while (msg[len--] == '=')
		new_len--;
	// printf("new_len: %zu\n", new_len);
	return (new_len + 1);
}

uint32_t		b64_decode_val(uint8_t *msg, size_t *i, size_t len)
{
	size_t		p;
	uint32_t	tmp;
	int			l_shift;

	p = 0;
	l_shift = 18;
	tmp = 0;
	while (p < 4 && *i < len)
	{
		if (ft_isspace(msg[*i]) == 1)
			*i += 1;
		else
		{
			tmp += ((msg[*i] == '=') ? 0 & *i : g_base64_d[msg[*i]]) << l_shift;
			l_shift += (l_shift == 0) ? 18 : -6;
		}
		*i += 1;
		p++;
	}
	return (tmp);
}

uint8_t			*base64_decode(uint8_t *msg, size_t len)
{
	uint8_t		*plain_msg;
	size_t		len_plain;
	size_t		i;
	size_t		j = 0;
	uint32_t	tmp;

	i = -1;
	len_plain = b64_decode_len(msg, len);
	if (!(plain_msg = (uint8_t*)ft_memalloc(sizeof(uint8_t) * len_plain)))
		return (NULL);
	while (j < len_plain && i < len)
	{
		tmp = b64_decode_val(msg, &i, len);
	}
	return (plain_msg);
}

// uint8_t			*base64_decode(uint8_t *msg, size_t len)
// {
// 	t_base64_decode	n;
// 	size_t			len_plain;
// 	uint8_t			*plain_msg;
// 	size_t			i;
// 	size_t			j;
// 	size_t			p = 0;
// 	size_t			l_shift = 18;
// 	size_t			r_shift = 16;

// 	i = 0;
// 	j = 0;
// 	n = (t_base64_decode){0,0,0,0,0};
// 	len_plain = b64_len_decode(msg, len);
// 	if (!(plain_msg = (uint8_t*)ft_memalloc(sizeof(uint8_t) * len_plain)))
// 		return (NULL);
// 	while (i < len)
// 	{
// 		if (ft_isspace(msg[i]) == 1)
// 			i++;
// 		else
// 		{
// 			n.tmp += g_base64_d[msg[i]] << l_shift;
// 			printf("l_shift: %zu\n", l_shift);
// 			ft_membits(&(n.tmp), 0, sizeof(uint32_t));
// 			l_shift += (l_shift == 0) ? 18 : -6;
// 			p++;
// 			if (p == 4)
// 			{
// 				printf("here\n");
// 				while (j < (len_plain - 1))
// 				{
// 					printf("r_shift: %zu\n", r_shift);
// 					plain_msg[j++] = (n.tmp >> r_shift) & 0xff;
// 					if (r_shift == 0)
// 						break ;
// 					else
// 						r_shift -= 8;
// 				}
// 				r_shift = 16;
// 				p = 0;
// 				n.tmp = 0;
// 			}
// 			i++;
// 		}
// 	}
// 	return (plain_msg);
// }

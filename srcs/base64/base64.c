/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:53:29 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/12 19:55:55 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

const char		g_base64_c[] =
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
	'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', '+', '/'
};

static void		base64_encode(void *s, size_t len)
{
	size_t		i;
	// uint32_t	n;
	// uint8_t		n0, n1, n2, n3 = 0;
	size_t		padding_len;

	i = 0;
	padding_len = len % 3;
	// n = 0;
	ft_membits(s, len, sizeof(uint8_t));
	printf("padding_len: %zu\n", padding_len);
	while (i < len)
	{
		// printf("n0: %2d, c: %c\n", n0, g_base64_c[n0]);
		// printf("n1: %2d, c: %c\n", n1, g_base64_c[n1]);
		// printf("n2: %2d, c: %c\n", n2, g_base64_c[n2]);
		// printf("n3: %2d, c: %c\n", n3, g_base64_c[n3]);
		i += 3;
	}
}

static void		base64_decode(void *s, size_t len)
{
	(void)s, (void)len;
	printf("base64 decode func\n");
}

void	*base64(void *opts, size_t len_opts)
{
	t_opt	*opt;

	(void)len_opts;
	opt = (t_opt*)opts;
	if ((opt->flags.b64_flags & e_base64_encode) == e_base64_encode)
		base64_encode(opt->data->data, opt->data->len_data);
	else if ((opt->flags.b64_flags & e_base64_decode) == e_base64_decode)
		base64_decode(opt->data->data, opt->data->len_data);
	print_lst(&opt);
	return (opts);
}

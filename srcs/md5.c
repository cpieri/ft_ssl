/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:18:34 by cpieri            #+#    #+#             */
/*   Updated: 2019/01/25 18:35:09 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include <stdio.h>

static int*		stoi(char *s)
{
	int		*ret;
	int		i;

	i = 0;
	if (!(ret = (int*)malloc(sizeof(int) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
		ret[i] = (int)s[i];
	return (ret);
}

static void		padding(char *s, int len)
{
	int		*msg;
	int		nb_bits;
	int		do_padding;

	msg = stoi(s);
	nb_bits = len * 8;
	msg = msg << 1 | 1;
	do_padding = 512 - 64 - 1 - nb_bits;
	printf("%s have %u bits, we do padding %u\n", s, nb_bits, do_padding);	
}

void			md5(char* s)
{
	int		len;

	len = ft_strlen(s);
	padding(s, len);
}

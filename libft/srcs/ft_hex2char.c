/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex2char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:21:06 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/20 21:43:55 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_32hexa(char **s, size_t now, size_t len_s, uint32_t hex)
{
	if (hex > 15)
		put_32hexa(s, (now + 1), len_s, (hex / 16));
	hex %= 16;
	if (now < len_s)
	{
		if (hex < 10)
			(*s)[now] = hex % 10 + '0';
		else
			(*s)[now] = hex + 'a' - 10;
	}
}

char	*ft_hex2char(uint32_t hex, size_t nb_bytes)
{
	char	*s;
	int		now;

	if (!(s = (char*)ft_memalloc(sizeof(char) * (nb_bytes / 8))))
		return (NULL);
	now = 0;
	if (hex < 16)
		s[now] = '0';
	put_32hexa(&s, now, (nb_bytes / 8), hex);
	return (s);
}

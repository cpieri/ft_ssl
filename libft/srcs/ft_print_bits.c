/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:48:06 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/12 17:32:11 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void    ft_print_bits(unsigned char octet)
{
	int		z;
	int		oct;

	oct = octet;
	z = 128;
	while (z > 0)
	{
		if (oct & z)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		z >>= 1;
	}
	write(1, " ", 1);
}

void	ft_mem_bits(void *s, size_t len)
{
	size_t			i;
	unsigned char	*data;

	i = 0;
	data = (unsigned char*)s;
	while (i <= len)
		ft_print_bits(data[i++]);
	write(1, "\n", 1);
}

void	ft_str_bits(char *s)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
		ft_print_bits(s[i++]);
	write(1, "\n", 1);
}

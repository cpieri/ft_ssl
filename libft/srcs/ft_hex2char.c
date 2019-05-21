/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex2char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:21:06 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/21 09:30:45 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		calc_nb_len(uint32_t hex)
{
	long	len;

	len = 0;
	if (hex < 16)
		++len;
	while (hex /= 16)
		++len;
	++len;
	return (len);
}

// static void	put_32hexa(char **s, long len_s, uint32_t hex)
// {
// 	if (hex > 15)
// 		put_32hexa(s, (len_s - 1), (hex / 16));
// 	hex %= 16;
// 	if (len_s >= 0)
// 	{
// 		if (hex < 10)
// 			(*s)[len_s] = hex % 10 + '0';
// 		else
// 			(*s)[len_s] = hex + 'a' - 10;
// 	}
// }

void	swap_s(char **s, long len)
{
	long	i;
	char	tmp;

	i = 0;
	while (i < len)
	{
		tmp = (*s)[i];
		(*s)[i] = (*s)[len];
		(*s)[len] = tmp;
		i++;
		len--;
	}
}

static void	put_32hexa(char **s, long len_s, uint32_t hex)
{
	uint32_t	nb;
	long		i;

	nb = 0;
	i = 0;
	while (i <= len_s)
	{
		nb = hex % 16;
		if (nb < 10)
			(*s)[i] = (nb) % 10 + '0';
		else
			(*s)[i] = (nb) + 'a' - 10;
		hex /= 16;
		i++;
	}
}

char	*ft_hex2char(uint32_t hex, size_t nb_bytes)
{
	char	*s;
	long	len;

	(void)nb_bytes;
	len = calc_nb_len(hex);
	if (!(s = (char*)ft_memalloc(sizeof(char) * (len))))
		return (NULL);
	if (hex < 16)
		s[0] = '0';
	put_32hexa(&s, len - 1, hex);
	// swap_s(&s, len - 1);
	return (s);
}

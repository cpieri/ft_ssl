/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_membits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:08:47 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/12 16:06:32 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_membits(void *s, size_t len)
{
	size_t			i;
	unsigned char	*data;

	data = (unsigned char*)s;
	i = 0;
	while (i <= len)
	{
		ft_putbits(data[i++]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

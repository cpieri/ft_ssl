/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:04:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/07 18:06:09 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strbits(char *s)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
		ft_putbits(s[i++]);
	ft_putchar('\n');
}
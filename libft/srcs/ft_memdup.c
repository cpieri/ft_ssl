/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:34:44 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/04 17:29:58 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s1, size_t len)
{
	size_t	i;
	char	*src;
	char	*s2;

	i = 0;
	src = (char*)s1;
	if (!src)
		return (NULL);
	if (!(s2 = (char*)ft_memalloc(sizeof(char) * (len + 1))))
	{
		ft_memdel((void**)&s2);
		return (NULL);
	}
	while (i <= len)
	{
		s2[i] = src[i];
		i++;
	}
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:49:31 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/06 12:58:31 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishexa(char *s)
{
	int		i;

	i = 0;
	// if (s[1] != '0' && s[2] != 'x')
	// 	return (0);
	while (i <= 16)
	{
		if (s[i] < 48 && s[i] > 57 && s[i] < 'A' && s[i] > 'F')
			return (0);
		i++;
	}
	return (1);
}
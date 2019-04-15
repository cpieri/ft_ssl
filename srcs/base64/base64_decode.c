/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_decode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:41:31 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/15 15:16:01 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64/base64.h"
#include <stdio.h>

uint8_t		*base64_decode(uint8_t *msg, size_t len)
{
	size_t			i;
	t_base64_encode	n;

	i = 0;
	printf("decode func\n");
	y = 0;
	while (i < len)
	{
		if (ft_isspace(msg[i]))
			i++;
		i++;
	}
	return (msg);
}

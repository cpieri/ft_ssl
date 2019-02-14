/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:34:11 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/13 17:07:45 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

uint32_t	func_f(uint32_t b, uint32_t c, uint32_t d)
{
	return ((b & c) | ((~b) & d));
}

uint32_t	func_g(uint32_t b, uint32_t c, uint32_t d)
{
	return ((d & b) | ((~d) & c));
}

uint32_t	func_h(uint32_t b, uint32_t c, uint32_t d)
{
	return (b ^ c ^ d);
}

uint32_t	func_i(uint32_t b, uint32_t c, uint32_t d)
{
	return (c ^ (b | (~d)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:34:11 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/05 18:04:50 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

t_md5_utils	func_f(uint32_t b, uint32_t c, uint32_t d, int i)
{
	t_md5_utils	ret;

	ret.f = (b & c) | ((~b) & d);
	ret.g = i;
	return (ret);
}

t_md5_utils	func_g(uint32_t b, uint32_t c, uint32_t d, int i)
{
	t_md5_utils	ret;

	ret.f = (d & b) | ((~d) & c);
	ret.g = (5 * i + 1) % 16;
	return (ret);
}

t_md5_utils	func_h(uint32_t b, uint32_t c, uint32_t d, int i)
{
	t_md5_utils	ret;

	ret.f = b ^ c ^ d;
	ret.g = (3 * i + 5) % 16;
	return (ret);
}

t_md5_utils	func_i(uint32_t b, uint32_t c, uint32_t d, int i)
{
	t_md5_utils	ret;

	ret.f = c ^ (b | (~d));
	ret.g = (7 * i) % 16;
	return (ret);
}

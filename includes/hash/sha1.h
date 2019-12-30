/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 08:05:02 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/30 08:59:37 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA1_H
# define SHA1_H

# include "hash.h"

# define SHA1_H0		0x67452301
# define SHA1_H1		0xEFCDAB89
# define SHA1_H2		0x98BADCFE
# define SHA1_H3		0x10325476
# define SHA1_H4		0xC3D2E1F0

typedef struct	s_sha1_utils
{
	uint32_t	f;
	uint32_t	k;
}				t_sha1_utils;

typedef struct	s_sha1
{
	t_padding	p;
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	h0;
	uint32_t	h1;
	uint32_t	h2;
	uint32_t	h3;
	uint32_t	h4;
	uint32_t	*w;
}				t_sha1;

t_sha1_utils	func_sha1_f(uint32_t b, uint32_t c, uint32_t d);
t_sha1_utils	func_sha1_g(uint32_t b, uint32_t c, uint32_t d);
t_sha1_utils	func_sha1_h(uint32_t b, uint32_t c, uint32_t d);
t_sha1_utils	func_sha1_i(uint32_t b, uint32_t c, uint32_t d);
void			*sha1(void *data, size_t len_data);
t_hash			*set_hash2sha1(t_sha1 *e);

#endif
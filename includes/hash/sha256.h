/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:15:42 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/31 08:47:28 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include "hash.h"

# define SHA256_H0		0x6A09E667
# define SHA256_H1		0xBB67AE85
# define SHA256_H2		0x3C6EF372
# define SHA256_H3		0xA54FF53A
# define SHA256_H4		0x510E527F
# define SHA256_H5		0x9B05688C
# define SHA256_H6		0x1F83D9AB
# define SHA256_H7		0x5BE0CD19

typedef struct	s_sha256_utils
{
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	ch;
	uint32_t	maj;
	uint32_t	tmp1;
	uint32_t	tmp2;
}				t_sha256_utils;

typedef struct	s_sha256
{
	t_padding	p;
	uint32_t	h0;
	uint32_t	h1;
	uint32_t	h2;
	uint32_t	h3;
	uint32_t	h4;
	uint32_t	h5;
	uint32_t	h6;
	uint32_t	h7;
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
	uint32_t	*w;
}				t_sha256;

void			*sha256(void *data, size_t len_data);
t_hash			*set_hash2sha256(t_sha256 *e);

#endif

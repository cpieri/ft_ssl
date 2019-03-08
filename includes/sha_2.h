/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:15:42 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/08 13:28:24 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_2_H
# define SHA_2_H

# include "hash.h"

# define h0		0x6a09e667
# define h1		0xbb67ae85
# define h2		0x3c6ef372
# define h3		0xa54ff53a
# define h4		0x510e527f
# define h5		0x9b05688c
# define h6		0x1f83d9ab
# define h7		0x5be0cd19

typedef struct	s_sha256_utils
{
	uint32_t	s0;
	uint32_t	s1;
}				t_sha256_utils;

typedef struct	s_sha256
{
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

t_hash			*sha256(void *data, size_t len_data);

#endif

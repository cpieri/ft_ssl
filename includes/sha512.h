/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:57:57 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/22 19:01:51 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_H
# define SHA512_H

# define SHA512_H0		0x6a09e667f3bcc908
# define SHA512_H1		0xbb67ae8584caa73b
# define SHA512_H2		0x3c6ef372fe94f82b
# define SHA512_H3		0xa54ff53a5f1d36f1
# define SHA512_H4		0x510e527fade682d1
# define SHA512_H5		0x9b05688c2b3e6c1f
# define SHA512_H6		0x1f83d9abfb41bd6b
# define SHA512_H7		0x5be0cd19137e2179

t_hash		*sha512(void *data, size_t len_data);

typedef struct	s_sha256
{
	t_padding	p;
	uint64_t	h0;
	uint64_t	h1;
	uint64_t	h2;
	uint64_t	h3;
	uint64_t	h4;
	uint64_t	h5;
	uint64_t	h6;
	uint64_t	h7;
	uint64_t	a;
	uint64_t	b;
	uint64_t	c;
	uint64_t	d;
	uint64_t	e;
	uint64_t	f;
	uint64_t	g;
	uint64_t	h;
	uint64_t	*w;
}				t_sha256;



#endif

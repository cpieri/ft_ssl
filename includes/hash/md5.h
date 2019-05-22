/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:16:22 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/22 09:41:05 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "hash.h"

# define MD5_H0	0x67452301
# define MD5_H1	0xEFCDAB89
# define MD5_H2	0x98BADCFE
# define MD5_H3	0x10325476

typedef struct	s_md5_utils
{
	uint32_t	f;
	uint32_t	g;
}				t_md5_utils;

typedef struct	s_md5
{
	t_padding	p;
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	h0;
	uint32_t	h1;
	uint32_t	h2;
	uint32_t	h3;
	uint32_t	*w;
}				t_md5;

t_md5_utils		func_f(uint32_t b, uint32_t c, uint32_t d, int i);
t_md5_utils		func_g(uint32_t b, uint32_t c, uint32_t d, int i);
t_md5_utils		func_h(uint32_t b, uint32_t c, uint32_t d, int i);
t_md5_utils		func_i(uint32_t b, uint32_t c, uint32_t d, int i);
char			*set_hash2md5(t_md5 *e);
void			*md5(void *data, size_t len_data);

#endif

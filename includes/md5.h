/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:16:22 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/07 15:32:37 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "../libft/include/libft.h"

# define	MD5_H0	0x67452301
# define	MD5_H1	0xEFCDAB89
# define	MD5_H2	0x98BADCFE
# define	MD5_H3	0x10325476

typedef struct	s_hash
{
	uint32_t	*h;
	size_t		nb_word;
}				t_hash;

typedef struct	s_md5_utils
{
	uint32_t	f;
	uint32_t	g;
}				t_md5_utils;

typedef struct	s_md5
{
	size_t		init_len;
	size_t		new_len;
	size_t		nb_bits;
	size_t		offest;
	uint8_t		*str_bits;
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
t_hash			*set_hash(t_md5 *e);
t_hash			*md5(void *data, size_t len_data);

#endif

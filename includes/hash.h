/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:41:09 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/22 15:56:23 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include "../libft/include/libft.h"

# define SET_MD5 {.name = "MD5", .fparse = hash_opts, .func = md5}
# define SET_SHA256 {.name = "SHA256", .fparse = hash_opts, .func = sha256}

typedef struct	s_hash
{
	uint32_t	*h;
	size_t		nb_word;
}				t_hash;

typedef struct	s_padding
{
	size_t		init_len;
	size_t		new_len;
	size_t		nb_bits;
	size_t		offest;
	uint8_t		*msg8;
}				t_padding;

#endif

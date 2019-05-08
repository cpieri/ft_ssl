/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:41:09 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/08 12:58:06 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include "../../libft/include/libft.h"
# include "../structure.h"

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

t_opt			*hash_opts(const int ac, char **av, t_opt *opts, int now);
void			printing_hash(t_data *data, const char *hash_type, t_flags flags);

#endif

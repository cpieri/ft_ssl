/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:13:19 by cpieri            #+#    #+#             */
/*   Updated: 2020/05/04 12:22:26 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DES_H
# define DES_H

# include "../../../libft/include/libft.h"
# include "../../structure.h"

typedef struct	s_des_key
{
	uint8_t		*key_left;
	uint8_t		*key_right;
	size_t		len_key_left;
	size_t		len_key_right;
}				t_des_key;

void		*des(void *opt, size_t len_opt);
uint8_t		*des_permute(uint8_t *to_perm, const int *arr, size_t new_len);
t_des_key	des_key_schedule(void *key, size_t key_len);

#endif

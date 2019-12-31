/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf2_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 13:31:54 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/06 10:57:10 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbkdf2/pbkdf.h"

t_pbkdf		*new_key(uint8_t *pass, void *salt, uint64_t key, uint64_t vect)
{
	t_pbkdf	*new;

	if (!(new = (t_pbkdf*)malloc(sizeof(t_pbkdf))))
		return (NULL);
	new->pass = pass;
	new->pass_len = ft_strlen((char*)new->pass);
	new->salt = (salt != NULL) ? salt : get_random();
	new->salt_len = ft_strlen((char*)new->salt);
	new->key = (key != 0x00) ? &key : 0x00;
	new->vect = vect;
	return (new);
}

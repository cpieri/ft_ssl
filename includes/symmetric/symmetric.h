/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:11:43 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/06 14:39:29 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMMETRIC_H
# define SYMMETRIC_H

# include "../libft/include/libft.h"
// # include "./des/des.h"

typedef struct	s_sym_key
{
	uint8_t		*pass;
	uint64_t	salt;
	uint64_t	key;
}				t_sym_key;

// void	*cbc(void *msg, void *key, size_t msg_len, size_t key_len);
// void	*ecb(void *msg, void *key, size_t msg_len, size_t key_len);

/*
**	Functions for create and del struct symmetric key
*/
uint8_t			*get_pass(const char *prompt);
t_sym_key		*new_key(uint8_t *pass, uint64_t salt, uint64_t key);
void			free_sym_key(t_sym_key **to_free);
void			free_sym_key(t_sym_key **to_free);

#endif
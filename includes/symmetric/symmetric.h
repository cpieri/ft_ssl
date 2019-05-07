/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:11:43 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/07 16:07:25 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMMETRIC_H
# define SYMMETRIC_H

# include "../../libft/include/libft.h"
# include "../structure.h"
// # include "./des/des.h"

enum			e_sym_opt
{
	e_sym_opt_a = 1,
	e_sym_opt_d,
	e_sym_opt_e,
	e_sym_opt_i,
	e_sym_opt_o,
	e_sym_opt_k,
	e_sym_opt_p,
	e_sym_opt_s,
	e_sym_opt_v
};

typedef struct	s_sym_key
{
	uint8_t		*pass;
	uint64_t	salt;
	uint64_t	key;
	uint64_t	vect;
}				t_sym_key;

typedef struct	s_sym_opt
{
	char		opt;
	int			flag;
	void		(*sym_opt_fun)(char **, int *, t_opt *, t_sym_key **);
}				t_sym_opt;

// void	*cbc(void *msg, void *key, size_t msg_len, size_t key_len);
// void	*ecb(void *msg, void *key, size_t msg_len, size_t key_len);

/*
**	Functions for get options in parsing
*/
void			get_sym_opt_i(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_o(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_k(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_s(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_p(char **av, int *now, t_opt *opt, t_sym_key **k);

/*
**	Functions for create and del struct symmetric key
*/
uint8_t			*get_pass(const char *prompt);
t_sym_key		*new_key(uint8_t *pass, uint64_t salt, uint64_t key, uint64_t vect);
void			print_t_key(t_sym_key *to_print);
void			free_sym_key(t_sym_key **to_free);
void			free_sym_key(t_sym_key **to_free);

/*
**	Usage
*/
void			sym_usage(const char *opt);

#endif
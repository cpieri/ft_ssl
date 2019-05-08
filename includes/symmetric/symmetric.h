/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:11:43 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/08 13:04:24 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMMETRIC_H
# define SYMMETRIC_H

# include "../../libft/include/libft.h"
# include "../structure.h"

enum			e_sym_opt
{
	e_sym_opt_a = 0x000000001,
	e_sym_opt_d = 0x000000010,
	e_sym_opt_e = 0x000000100,
	e_sym_opt_i = 0x000001000,
	e_sym_opt_o = 0x000010000,
	e_sym_opt_k = 0x000100000,
	e_sym_opt_p = 0x001000000,
	e_sym_opt_s = 0x010000000,
	e_sym_opt_v = 0x100000000
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
	uint64_t	flag;
	void		(*sym_opt_fun)(char **, int *, t_opt *, t_sym_key **);
}				t_sym_opt;

/*
**	Functions for get options in parsing
*/
t_opt			*symmetric_opts(const int ac, char **av, t_opt *opts, int now);
void			get_sym_opt_a(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_d(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_e(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_i(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_o(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_k(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_s(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_p(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_opt_v(char **av, int *now, t_opt *opt, t_sym_key **k);
void			get_sym_stdin(t_opt *opt, t_sym_key **k);

/*
**	Functions for create and del struct symmetric key
*/
uint8_t			*get_pass(const char *prompt);
t_sym_key		*new_key(uint8_t *pass, uint64_t salt, uint64_t key,
				uint64_t vect);
void			print_t_key(t_sym_key *to_print);
void			free_sym_key(t_sym_key **to_free);
void			free_sym_key(t_sym_key **to_free);

/*
**	Usage
*/
void			sym_usage(const char *opt);

#endif

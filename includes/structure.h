/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:27:48 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/08 12:46:04 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct		s_data
{
	const char		*fd_output;
	const char		*fd_name;
	char			*data;
	size_t			len_data;
	int				mall;
	void			*pass;
	void			*data_2_print;
}					t_data;

typedef struct		s_flags
{
	int				p;
	int				q;
	int				r;
	int				s;
	uint32_t		b64_flags;
	uint64_t		sym_flags;
}					t_flags;

typedef struct		s_opt
{
	t_data			*data;
	t_flags			flags;
	struct s_opt	*next;
}					t_opt;

typedef	struct		s_parse
{
	const char		*cmd;
	const char		*name;
	int				is_ciphash;
	void			*(*func)(void *, size_t);
	t_opt			*(*fparse)(const int, char **, t_opt *, int);
	void			(*fprint)(t_data *, const char *, t_flags);
	t_opt			*lst_opts;
}					t_parse;

#endif

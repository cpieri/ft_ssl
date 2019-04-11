/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:27:48 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 12:42:56 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct		s_data
{
	const char		*fd_name;
	char			*data;
	size_t			len_data;
	int				mall;
	t_hash			*f_hash;
}					t_data;

typedef struct		s_flags
{
	int				p;
	int				q;
	int				r;
	int				s;
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
	t_hash			*(*func)(void *, size_t);
	t_opt			*(*fparse)(const int, char **, t_opt *, int);
	t_opt			*lst_opts;
}					t_parse;


#endif
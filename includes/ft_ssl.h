/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:40:02 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/26 12:14:38 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/include/libft.h"
# include "./md5.h"
# include "./sha256.h"
# include "./sha512.h"

# define FAILURE			-1
# define SUCCESS			0

# define MD5				1
# define SHA256				2

# define NO_CMD				1
# define INVALID_CMD		2

enum		e_hash
{
	e_md5 = 1,
	e_sha256,
};

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
	enum e_hash		hash_type;
	t_hash			*(*func)(void *, size_t);
	t_opt			*(*fparse)(const int, char **, t_opt *, int);
	char			*name;
	t_opt			*lst_opts;
}					t_parse;

/*
**	Functions for Parsing
*/
t_parse				parsing(const int ac, char **av);
t_opt				*hash_opts(const int ac, char **av, t_opt *opts, int now);
int					open_fd(const char *file);
t_data				*get_data(const int fd, const char *fd_name);
t_data				*get_file(const int fd, const char *fd_name);
t_data				*get_string(char *s);

/*
**	Functions for Lst_opt
*/
t_opt				*new_opt(t_flags flags, t_data *data);
void				add_to_end_lst(t_opt *new, t_opt **lst);
void				print_lst(t_opt **lst);

/*
**	Functions for Hashing msg and display final hash
*/
void				hashing(t_parse *parse);
void				printing_hash(t_data *data, char *hash_type, t_flags flags);

/*
**	Functions for Exit, Clean, Error
*/
void				exit_error(void);
void				exit_error_free(void **to_free);
void				print_error(const char *msg_1);
void				print_usage(const int usage_int, const char *command);
void				clean_prog(t_parse *parse);

#endif

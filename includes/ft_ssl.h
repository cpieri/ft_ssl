/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:40:02 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/06 13:00:24 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/include/libft.h"
# include "./md5.h"

# define	FAILURE			-1
# define	SUCCESS			0
# define	OP_TAB_LEN		64
# define	BLOCK_TAB_LEN	16

# define	ARG_S			1
# define	ARG_R			2
# define	ARG_P			3
# define	ARG_Q			4

# define	MD5				1
# define	SHA256			2

# define	NO_CMD			1
# define	INVALID_CMD		2

typedef struct		s_data
{
	const char		*file_name;
	char			*data;
	size_t			len_data;
}					t_data;

typedef struct		s_flags
{
	int				flag_p;
	int				flag_q;
	int				flag_r;
	int				flag_s;
}					t_flags;

typedef struct		s_opt
{
	t_flags			flags;
	t_data			*data;
	struct s_opt	*next;
}					t_opt;

typedef	struct		s_parse
{
	int				hash_type;
	t_opt			*lst_opts;
}					t_parse;

typedef struct		s_block
{
	uint32_t		*tab;
	struct s_block	*next;
}					t_block;

t_parse		parsing(const int ac, char **av);
int			open_fd(const char *file);
t_data		*get_data(const int fd, const char *fd_name);
t_data		*get_string(char *s);
void		hashing(t_parse *parse);
t_opt		*new_opt(int flag, t_data *data);
void    	add_to_end_lst(t_opt *new, t_opt **lst);
void		print_lst(t_opt **lst);
void		add_2_end_lstblocks(t_block *new, t_block **lst);
t_block		*new_block(void);

void		exit_error(const char *msg);
void		print_usage(const int usage_int, const char *command);

#endif

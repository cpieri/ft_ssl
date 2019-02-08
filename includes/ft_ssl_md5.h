/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:04:27 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/08 17:55:14 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include "../libft/include/libft.h"

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

typedef struct		s_opt
{
	int				flag;
	char			*data;
	struct s_opt	*next;
}					t_opt;

typedef	struct		s_parse
{
	int				hash_type;
	t_opt			**lst_opts;
}					t_parse;

typedef struct		s_block
{
	uint32_t		*tab;
	struct s_block	*next;
}					t_block;

typedef struct		s_hash
{
	char			*name;
	uint32_t		args;
	char			*data;
}					t_hash;

typedef	struct		s_md5
{
	char*			org_str;
	size_t			org_len;
	size_t			org_nb_bits;
	int				nb_blocks;
}					t_md5;


int		parsing(int ac, char **av);
char	*get_data(const int fd);
void	print_usage(const int usage_int, const char *command);
void	md5(char *s);
t_opt	*new_opt(int flag, char *data);

void	exit_error(const char *msg);

#endif

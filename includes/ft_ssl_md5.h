/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:04:27 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/05 18:06:42 by cpieri           ###   ########.fr       */
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

# define	MD5_H0			0x67452301
# define	MD5_H1			0xEFCDAB89
# define	MD5_H2			0x98BADCFE
# define	MD5_H3			0x10325476

# define	R(n) ((n >> 24) | ((n & 0xff0000) >> 8))

typedef struct		s_data
{
	char			*data;
	size_t			len_data;
}					t_data;

typedef struct		s_opt
{
	int				flag;
	//char			*data;
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

typedef struct		s_md5_utils
{
	uint32_t		f;
	uint32_t		g;
}					t_md5_utils;

typedef struct		s_md5
{
	size_t			init_len;
	size_t			new_len;
	size_t			nb_bits;
	size_t			offest;
	uint8_t			*str_bits;
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		h0;
	uint32_t		h1;
	uint32_t		h2;
	uint32_t		h3;
	uint32_t		*w;
}					t_md5;

t_parse		parsing(const int ac, char **av);
int			open_fd(const char *file);
t_data		*get_data(const int fd);
t_data		*get_string(char *s);
void		hashing(t_parse *parse);
void		md5(void *data, size_t len_data);
t_md5_utils	func_f(uint32_t b, uint32_t c, uint32_t d, int i);
t_md5_utils	func_g(uint32_t b, uint32_t c, uint32_t d, int i);
t_md5_utils	func_h(uint32_t b, uint32_t c, uint32_t d, int i);
t_md5_utils	func_i(uint32_t b, uint32_t c, uint32_t d, int i);
t_opt		*new_opt(int flag, t_data *data);
void    	add_to_end_lst(t_opt *new, t_opt **lst);
void		print_lst(t_opt **lst);
void		add_2_end_lstblocks(t_block *new, t_block **lst);
t_block		*new_block(void);

void		exit_error(const char *msg);
void		print_usage(const int usage_int, const char *command);

#endif

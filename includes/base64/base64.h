/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:59:40 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/08 13:03:15 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include "../libft/include/libft.h"
# include "../structure.h"

enum			e_base64_flags
{
	e_base64_encode = 0x00000001,
	e_base64_decode = 0x00000010,
	e_base64_inputf = 0x00000100,
	e_base64_outputf = 0x00001000,
};

typedef struct	s_base64_encode
{
	uint8_t		n0;
	uint8_t		n1;
	uint8_t		n2;
	uint8_t		n3;
}				t_base64_encode;

/*
**	Encode/Decode Base64
*/
void			*base64(void *opts, size_t len_opts);
uint8_t			*base64_encode(uint8_t *msg, size_t len);
uint8_t			*base64_decode(uint8_t *msg, size_t len);

/*
**	Functions for Print Base64
*/
void			printing_base64(t_data *data, const char *hash_type,
				t_flags flags);

/*
**	Funtions for Parse opts Base64
*/
t_opt			*base64_opts(const int ac, char **av, t_opt *opts, int now);
void			get_b64_ed(t_data **data, t_flags *flags, char *fd, char c);
void			get_b64_i(t_data **data, t_flags *flags, char *fd, int *now);

#endif

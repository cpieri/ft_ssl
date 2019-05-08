/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:59:40 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/08 10:53:06 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include "../libft/include/libft.h"

enum	e_base64_flags
{
	e_base64_encode = 0x00000001,
	e_base64_decode = 0x00000010,
	e_base64_inputf = 0x00000100,
	e_base64_outputf = 0x00001000,
};

typedef struct		s_base64_encode
{
	uint8_t			n0;
	uint8_t			n1;
	uint8_t			n2;
	uint8_t			n3;
}					t_base64_encode;

uint8_t				*base64_encode(uint8_t *msg, size_t len);
uint8_t				*base64_decode(uint8_t *msg, size_t len);

#endif

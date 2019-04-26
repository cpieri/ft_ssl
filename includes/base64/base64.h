/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:59:40 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/26 16:59:21 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include "../libft/include/libft.h"

typedef struct		s_base64_encode
{
	uint8_t			n0;
	uint8_t			n1;
	uint8_t			n2;
	uint8_t			n3;
}					t_base64_encode;

typedef struct		s_base64_decode
{
	uint32_t		n0;
	uint32_t		n1;
	uint32_t		n2;
	uint32_t		n3;
	uint32_t		tmp;
}					t_base64_decode;

uint8_t				*base64_encode(uint8_t *msg, size_t len);
uint8_t				*base64_decode(uint8_t *msg, size_t len);

#endif

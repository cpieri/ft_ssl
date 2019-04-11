/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:03:37 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 14:24:57 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BASE64_H
# define BASE64_H

typedef struct	s_base64
{
	uint32_t	n;
}				t_base64;

char			*base64_encode(void *data, size_t len_data);
void			*base64(void *data, size_t len_data);

#endif
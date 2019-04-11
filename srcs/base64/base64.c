/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:07:41 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 14:36:09 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*base64_encode(void *data, size_t len_data)
{
	char	*encode_s = "test";

	(void)data, (void)len_data;
	return (encode_s);
}

void	*base64(void *data, size_t len_data)
{
	t_opt	*opt;
	char	*s;

	opt = (t_opt*)data;
	(void)len_data;
	s = NULL;
	if (opt->uint_flags & e_base64_encode)
		s = base64_encode(opt->data->data, opt->data->len_data);
	return (s);
}
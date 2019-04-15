/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:53:29 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/15 15:17:39 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "base64/base64.h"
#include <stdio.h>

void			*base64(void *opts, size_t len_opts)
{
	t_opt	*opt;

	(void)len_opts;
	opt = (t_opt*)opts;
	if ((opt->flags.b64_flags & e_base64_encode))
		base64_encode((uint8_t*)opt->data->data, opt->data->len_data);
	else if ((opt->flags.b64_flags & e_base64_decode))
		base64_decode((uint8_t*)opt->data->data, opt->data->len_data);
	return (opts);
}

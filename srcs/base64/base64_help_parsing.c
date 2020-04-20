/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_help_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:39:36 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/03 11:39:50 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "base64/base64.h"

void	get_b64_ed(t_data **data, t_flags *flags, char *fd, char c)
{
	if (*data != NULL && fd != NULL)
		clean_data(data);
	if (c == 'd')
	{
		flags->b64_flags |= e_base64_decode;
		if ((flags->b64_flags & e_base64_encode) == e_base64_encode)
			flags->b64_flags = (flags->b64_flags ^ e_base64_encode);
	}
	else if (c == 'e' && (flags->b64_flags & e_base64_decode) == 0)
		flags->b64_flags |= e_base64_encode;
	if (fd == NULL && *data == NULL)
		*data = get_data(0, NULL);
	else if (*data == NULL && fd != NULL)
		*data = get_file(open_fd(fd), fd);
}

void	get_b64_i(t_data **data, t_flags *flags, char *fd, int *now)
{
	flags->b64_flags |= e_base64_inputf;
	if (*data != NULL && fd != NULL)
		clean_data(data);
	*data = get_data(open_fd(fd), fd);
	(*now)++;
}

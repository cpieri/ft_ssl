/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_help_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:39:36 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/12 14:52:42 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	get_b64_ed(t_data **data, t_flags *flags, char *fd, char c)
{
	if (*data != NULL)
		clean_data(data);
	flags->b64_flags |= (c == 'd') ? e_base64_decode : e_base64_encode;
	if (fd == NULL)
		*data = get_data(0, NULL);
	else
		*data = get_file(open_fd(fd), fd);
}

void	get_b64_i(t_data **data, t_flags *flags, char *fd, int *now)
{
	flags->b64_flags |= e_base64_inputf;
	if (*data != NULL)
		clean_data(data);
	*data = get_data(open_fd(fd), fd);
	(*now)++;
}

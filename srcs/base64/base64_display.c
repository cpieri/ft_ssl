/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:13:14 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/30 14:28:28 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	printing_base64(t_data *data, const char *name, t_flags flags)
{
	const char	*msg_print;
	int			fd;

	fd = 1;
	(void)name;
	msg_print = (const char *)data->data_2_print;
	if ((flags.b64_flags & e_base64_outputf) == e_base64_outputf
			&& data->fd_output != NULL)
		fd = open_write_fd(data->fd_output);
	if (fd == FAILURE)
		print_error(data->fd_output);
	ft_putendl_fd(msg_print, fd);
	if ((flags.b64_flags & e_base64_outputf) == e_base64_outputf)
		close_fd(fd);
}

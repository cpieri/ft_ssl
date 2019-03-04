/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:54 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/04 17:35:57 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "ft_ssl_md5.h"

int		open_fd(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == FAILURE)
		exit_error("Open Failed");
	return (fd);
}

char	*get_data(const int fd)
{
	char	buffer[BUFF_SIZE + 1];
	char	*data = NULL;
	char	*tmp;
	int		nb_read;
	size_t	size_tmp;

	size_tmp = 0;
	while ((nb_read = read(fd, buffer, BUFF_SIZE)))
	{
		size_tmp += nb_read;
		if (data == NULL)
			data = ft_memdup(buffer, nb_read);
		else if (nb_read > 0)
		{
			tmp = data;
			data = ft_memjoin(tmp, buffer, size_tmp, nb_read);
			ft_strdel(&tmp);
		}
	}
	//data[size_tmp] = '\0';
	//printf("%s read:%zu\n", data, size_tmp);
	return (data);
}

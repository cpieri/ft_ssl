/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:54 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/05 17:44:22 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "ft_ssl_md5.h"

t_data	*get_string(char *s)
{
	t_data	*ret;

	ret = NULL;
	if (!(ret = (t_data*)malloc(sizeof(t_data))))
	{
		ft_memdel((void**)&ret);
		return (NULL);
	}
	ret->data = s;
	ret->len_data = ft_strlen(s);
	return (ret);
}

int		open_fd(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == FAILURE)
		exit_error("Open Failed");
	return (fd);
}

t_data	*get_data(const int fd)
{
	char	buffer[BUFF_SIZE + 1];
	t_data	*ret;
	char	*tmp;
	int		nb_read;

	tmp = NULL;
	if (!(ret = (t_data*)malloc(sizeof(t_data))))
	{
		ft_memdel((void**)&ret);
		return (NULL);
	}
	*ret = (t_data){.data = NULL, .len_data = 0};
	while ((nb_read = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret->data == NULL)
			ret->data = ft_memdup(buffer, nb_read);
		else if (nb_read > 0)
		{
			tmp = ret->data;
			ret->data = ft_memjoin(tmp, buffer, ret->len_data, nb_read);
			ft_memdel((void**)&tmp);
		}
		ret->len_data += nb_read;
	}
	return (ret);
}

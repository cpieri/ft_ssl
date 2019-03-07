/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:54 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/07 15:39:15 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_ssl.h"

t_data	*get_string(char *s)
{
	t_data	*ret;

	ret = NULL;
	if (!(ret = (t_data*)malloc(sizeof(t_data))))
	{
		ft_memdel((void**)&ret);
		exit_error("Malloc Failed: get_data.c:21:get_string()");
	}
	ret->file_name = s;
	ret->data = s;
	ret->len_data = ft_strlen(s);
	s = NULL;
	return (ret);
}

int		open_fd(const char *file)
{
	int		fd;
	char	*tmp;

	fd = open(file, O_RDONLY);
	tmp = NULL;
	if (fd == FAILURE)
	{
		if (close(fd) != 0)
			exit_error("Close Failed: get_data.c:41:open_fd()");
		exit_error("Open Failed: get_data.c:36:open_fd()");
	}
	if (read(fd, tmp, 0) == FAILURE)
	{
		if (close(fd) != 0)
			exit_error("Close Failed: get_data.c:47:open_fd()");
		ft_putstr_fd(file, 2);
		exit_error(": Is a directory");
	}
	return (fd);
}

t_data	*get_data(const int fd, const char *fd_name)
{
	char	buffer[BUFF_SIZE + 1];
	t_data	*ret;
	char	*tmp;
	int		nb_read;

	tmp = NULL;
	if (!(ret = (t_data*)malloc(sizeof(t_data))))
	{
		ft_memdel((void**)&ret);
		exit_error("Malloc Failed: get_data.c:50:get_data()");
	}
	*ret = (t_data){.data = NULL, .len_data = 0, .file_name = fd_name};
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

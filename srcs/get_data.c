/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:54 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/22 15:09:49 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_ssl.h"

t_data	*get_string(char *s)
{
	t_data	*ret;

	ret = NULL;
	if (!(ret = (t_data*)malloc(sizeof(t_data))))
		exit_error();
	ret->fd_name = s;
	ret->data = s;
	ret->len_data = ft_strlen(s);
	ret->mall = 0;
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
		print_error(file);
		return (-1);
	}
	if (read(fd, tmp, 0) == FAILURE)
	{
		if (close(fd) != 0)
			exit_error();
		print_error(file);
		return (-1);
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
	if (fd == -1)
		return (NULL);
	if (!(ret = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	*ret = (t_data){.data = NULL, .len_data = 0, .fd_name = fd_name, .mall = 1};
	while ((nb_read = read(fd, buffer, BUFF_SIZE)) > 0)
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
	return ((ret->data != NULL) ? ret : NULL);
}

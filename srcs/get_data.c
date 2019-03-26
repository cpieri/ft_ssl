/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:54 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/26 15:31:30 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_ssl.h"

t_data		*get_string(char *s)
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

int			open_fd(const char *file)
{
	int		fd;
	char	*tmp;

	fd = open(file, O_RDONLY);
	tmp = NULL;
	if (fd == FAILURE)
	{
		print_error(file);
		return (FAILURE);
	}
	if (read(fd, tmp, 0) == FAILURE)
	{
		if (close(fd) != 0)
			exit_error();
		print_error(file);
		return (FAILURE);
	}
	return (fd);
}

static int	reopen_fd(const int current_fd, const char *file)
{
	int		new_fd;

	if (close(current_fd) != 0)
		exit_error();
	if ((new_fd = open(file, O_RDONLY)) == FAILURE)
	{
		print_error(file);
		return (FAILURE);
	}
	return (new_fd);
}

t_data		*get_file(const int fd, const char *fd_name)
{
	char				buffer[BUFF_SIZE + 1];
	int					nb_read;
	int					fd_2;
	unsigned long long	size;
	t_data				*ret;

	size = 0;
	if (fd == FAILURE || !(ret = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	*ret = (t_data){.data = NULL, .len_data = 0, .fd_name = fd_name, .mall = 1};
	while ((nb_read = read(fd, buffer, BUFF_SIZE)) > 0)
		size += nb_read;
	if (nb_read == -1)
		exit_error_free((void**)&ret);
	if (!(ret->data = (char*)malloc(sizeof(char) * (size + 1)))
			|| (fd_2 = reopen_fd(fd, fd_name)) == FAILURE)
		return (NULL);
	while (read(fd_2, ret->data, size) > 0)
		ret->len_data = size;
	if (nb_read == -1)
		exit_error_free((void**)&ret);
	return ((ret->data != NULL) ? ret : NULL);
}

t_data		*get_data(const int fd, const char *fd_name)
{
	char	buffer[BUFF_SIZE + 1];
	t_data	*ret;
	char	*tmp;
	int		nb_read;

	tmp = NULL;
	if (fd == FAILURE || !(ret = (t_data*)malloc(sizeof(t_data))))
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
	if (nb_read == -1)
		exit_error_free((void**)&ret);
	return ((ret->data != NULL) ? ret : NULL);
}

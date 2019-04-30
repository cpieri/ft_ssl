/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:37:15 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/30 14:27:02 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_ssl.h"

int		open_write_fd(const char *file)
{
	int		fd;

	fd = open(file, O_WRONLY);
	if (fd == FAILURE)
	{
		fd = open(file, O_CREAT | O_WRONLY);
		if (fd == FAILURE)
		{
			print_error(file);
			return (FAILURE);
		}
	}
	return (fd);
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

int		reopen_fd(const int current_fd, const char *file)
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

int		close_fd(const int fd)
{
	if (close(fd) != 0)
	{
		print_error("base64 close");
		return (FAILURE);
	}
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:35:34 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/07 16:14:37 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <errno.h>

void	print_error(const char *msg)
{
	char	*error;

	ft_putstr_fd("ft_ssl: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	error = strerror(errno);
	ft_putendl_fd(error, 2);
}

void	exit_error_free(void **to_free)
{
	char	*error;

	ft_putstr_fd("ft_ssl: ", 2);
	error = strerror(errno);
	ft_putendl_fd(error, 2);
	ft_memdel(to_free);
	exit(FAILURE);
}

void	exit_error(void)
{
	char	*error;

	ft_putstr_fd("ft_ssl: ", 2);
	error = strerror(errno);
	ft_putendl_fd(error, 2);
	exit(FAILURE);
}

void	exit_error_msg(const char *msg)
{
	char	*error;

	ft_putstr_fd("ft_ssl: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	error = strerror(errno);
	ft_putendl_fd(error, 2);
	exit(FAILURE);
}

void	exit_msg(const char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(FAILURE);
}

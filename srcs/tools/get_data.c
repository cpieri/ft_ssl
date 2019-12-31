/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:54 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/07 15:31:42 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

t_data		*new_data(void)
{
	t_data	*ret;

	if (!(ret = (t_data*)malloc(sizeof(t_data))))
		exit_error();
	*ret = (t_data){NULL, NULL, NULL, 0, 0, NULL, NULL};
	return (ret);
}

t_data		*get_string(char *s)
{
	t_data	*ret;

	ret = NULL;
	if (!(ret = (t_data*)malloc(sizeof(t_data))))
		exit_error();
	*ret = (t_data){NULL, s, s, ft_strlen(s), 0, NULL, NULL};
	s = NULL;
	return (ret);
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
	(ret->data == NULL) ? ft_memdel((void**)&(ret->data)) : NULL;
	return (ret);
}

void		*get_random(void)
{
	unsigned char	*ret;
	uint64_t		random_value;
	int				dev_random_fd;
	int				nb_read;

	random_value = FAILURE;
	dev_random_fd = open_fd("/dev/random");
	nb_read = read(dev_random_fd, &random_value, sizeof(uint64_t));
	random_value = swap_uint64t(random_value);
	ret = ft_memdup(&random_value, sizeof(uint64_t));
	if (nb_read == FAILURE)
		print_error("get_random");
	return (ret);
}

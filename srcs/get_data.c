/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:54 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/08 12:30:29 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

int		get_data(const int fd, char **data)
{
	char			buffer[BUFF_SIZE + 1];
	static char		*save = NULL;
	char			*tmp;
	int				nb_read;

	while ((nb_read = read(fd, buffer, BUFF_SIZE)))
	{
		if (save == NULL)
			save = ft_strdup(buffer);
		else
		{
			tmp = save;
			save = ft_strjoin(tmp, buffer);
			ft_strdel(&tmp);
		}
	}
	*data = ft_strdup(save);
	ft_strdel(&save);
	return (SUCCESS);
}

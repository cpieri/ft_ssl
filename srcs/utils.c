/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:29:55 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/08 17:53:21 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

t_opt	*new_opt(int flag, char *data)
{
	t_opt	*new;

	if (!(new = (t_opt*)malloc(sizeof(t_opt))))
		return (NULL);
	if (!data)
	{
		new->data = NULL;
		new->flag = 0;
	}
	else
	{
		new->data = ft_strdup(data);
		new->flag = flag;
	}
	new->next = NULL;
	return (new);
}

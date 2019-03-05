/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:01:28 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/05 16:33:20 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void	hashing(t_parse *parse)
{
	int		hash_type;
	t_opt	*lst;

	hash_type = parse->hash_type;
	lst = parse->lst_opts;
	while (lst != NULL)
	{
		if (hash_type == MD5)
			md5(lst->data->data, lst->data->len_data);
		else if (hash_type == SHA256)
			continue ;
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
}

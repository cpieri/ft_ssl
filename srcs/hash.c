/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:01:28 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/08 15:52:06 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	hashing(t_parse *parse)
{
	int		hash_type;
	t_opt	*lst;

	hash_type = parse->hash_type;
	lst = parse->lst_opts;
	while (lst != NULL)
	{
		if (hash_type == MD5)
		{
			lst->data->f_hash = md5(lst->data->data, lst->data->len_data);
			printing_hash(lst->data, "MD5", lst->flags);
		}
		else if (hash_type == SHA256)
		{
			lst->data->f_hash = sha256(lst->data->data, lst->data->len_data);
			printing_hash(lst->data, "SHA256", lst->flags);
		}
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
}

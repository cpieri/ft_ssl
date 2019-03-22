/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:01:28 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/22 15:13:40 by cpieri           ###   ########.fr       */
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
		lst->data->f_hash = (parse->func)(lst->data->data, lst->data->len_data);
		printing_hash(lst->data, parse->name, lst->flags);
		lst = lst->next;
	}
}

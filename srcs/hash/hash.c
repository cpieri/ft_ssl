/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:01:28 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 11:16:22 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	hashing(t_parse *parse)
{
	t_opt	*lst;

	lst = parse->lst_opts;
	while (lst != NULL)
	{
		lst->data->f_hash = (parse->func)(lst->data->data, lst->data->len_data);
		printing_hash(lst->data, parse->name, lst->flags);
		lst = lst->next;
	}
}

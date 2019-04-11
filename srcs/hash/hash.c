/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:01:28 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 15:10:23 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	hashing(t_parse *parse)
{
	t_opt	*lst;

	lst = parse->lst_opts;
	while (lst != NULL)
	{
		if (parse->is_ciphash == e_hash)
			lst->data->f_hash = (t_hash*)parse->func(lst->data->data, lst->data->len_data);
		else if (parse->is_ciphash == e_cipher)
			parse->func(lst, 0);
		if (parse->fprint != NULL)
			parse->fprint(lst->data, parse->name, lst->flags);
		lst = lst->next;
	}
}

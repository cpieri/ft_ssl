/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:01:28 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/22 09:42:03 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	dispatch(t_parse *parse)
{
	t_opt	*lst;

	lst = parse->lst_opts;
	while (lst != NULL)
	{
		if (parse->is_ciphash == e_hash)
			lst->data->data_2_print = parse->func(lst->data->data,
					lst->data->len_data);
		else if (parse->is_ciphash == e_cipher)
			lst->data->data_2_print = parse->func(lst, 0);
		if (parse->fprint != NULL)
			parse->fprint(lst->data, parse->name, lst->flags);
		lst = lst->next;
	}
}

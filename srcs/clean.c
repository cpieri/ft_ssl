/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:07:14 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/20 17:23:26 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	clean_prog(t_parse *parse)
{
	t_opt	*next;
	t_opt	*lst;

	lst = parse->lst_opts;
	while (lst != NULL)
	{
		if (lst->data->mall == 1)
			ft_memdel((void**)&(lst->data->data));
		ft_memdel((void**)&(lst->data->f_hash->h));
		ft_memdel((void**)&(lst->data->f_hash));
		ft_memdel((void**)&(lst->data));
		if (lst->next != NULL)
		{
			next = lst->next;
			ft_memdel((void**)lst);
			lst = next;
			next = NULL;
		}
		else
			break ;
	}
	ft_memdel((void**)lst);
}

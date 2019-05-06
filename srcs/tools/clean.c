/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:07:14 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/12 10:25:09 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	clean_data(t_data **data)
{
	if (*data != NULL)
	{
		if ((*data)->mall == 1)
			ft_memdel((void**)&((*data)->data));
		if ((*data)->f_hash != NULL)
		{
			ft_memdel((void**)&((*data)->f_hash->h));
			ft_memdel((void**)&((*data)->f_hash));
		}
		ft_memdel((void**)data);
	}
}

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
		next = lst->next;
		ft_memdel((void**)&(lst));
		lst = next;
	}
	parse->lst_opts = NULL;
}

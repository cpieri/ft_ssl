/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:29:55 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 19:23:33 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_lst(t_opt **lst)
{
	t_opt	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		ft_memput(tmp->data->data, tmp->data->len_data);
		if (tmp->fd_output != NULL)
			ft_putendl(tmp->fd_output);
		tmp = tmp->next;
	}
}

void	add_to_end_lst(t_opt *new, t_opt **lst)
{
	t_opt	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_opt	*new_opt(t_flags flags, t_data *data)
{
	t_opt	*new;

	if (data == NULL)
		return (NULL);
	if (!(new = (t_opt*)malloc(sizeof(t_opt))))
		return (NULL);
	new->next = NULL;
	new->data = data;
	new->flags = flags;
	new->fd_output = NULL;
	return (new);
}

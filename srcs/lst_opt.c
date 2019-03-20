/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:29:55 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/19 20:15:12 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_lst(t_opt **lst)
{
	t_opt	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		ft_putendl(tmp->data->data);
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break ;
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

	if (!(new = (t_opt*)malloc(sizeof(t_opt))))
		return (NULL);
	if (!data)
	{
		new->data = NULL;
		new->flags = (t_flags){0, 0, 0, 0};
	}
	else
	{
		new->data = data;
		new->flags = flags;
	}
	new->next = NULL;
	return (new);
}

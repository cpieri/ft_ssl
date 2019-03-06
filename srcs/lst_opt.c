/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:29:55 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/06 12:47:47 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ssl.h"

void	print_lst(t_opt **lst)
{
	t_opt	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		ft_putnbr(tmp->flag);
		ft_putchar('\n');
		ft_putendl(tmp->data->data);
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break;
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

t_opt	*new_opt(int flag, t_data *data)
{
	t_opt	*new;

	if (!(new = (t_opt*)malloc(sizeof(t_opt))))
		return (NULL);
	if (!data)
	{
		new->data = NULL;
		new->flag = 0;
	}
	else
	{
		new->data = data;
		new->flag = flag;
	}
	new->next = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:29:55 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/20 12:15:32 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_lst(t_opt **lst)
{
	t_opt	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		ft_putstr("data to crypt: ");
		ft_memput(tmp->data->data, tmp->data->len_data);
		ft_membits(&tmp->flags.sym_flags, 0, sizeof(uint64_t));
		print_pbkdf((t_pbkdf*)(tmp->data->pass));
		if (tmp->data->fd_output != NULL)
		{
			ft_putstr("fd to output: ");
			ft_putendl(tmp->data->fd_output);
		}
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
	if (data->fd_output == NULL)
		new->data->fd_output = NULL;
	return (new);
}

t_opt	*new_opt_fd(t_flags flags, t_data *data, char *fd)
{
	t_opt	*new;

	if (data == NULL)
		return (NULL);
	if (!(new = (t_opt*)malloc(sizeof(t_opt))))
		return (NULL);
	new->next = NULL;
	new->data = data;
	new->flags = flags;
	new->data->fd_output = (fd != NULL) ? fd : NULL;
	return (new);
}

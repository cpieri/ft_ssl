/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:29:55 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/11 17:22:39 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ssl_md5.h"

/*void	print_lst(t_opt **lst)
  {
  t_opt	*tmp;

  tmp = *lst;
  while (tmp != NULL)
  {
  ft_putnbr(tmp->flag);
  ft_putchar('\n');
  ft_putendl(tmp->data);
  if (tmp->next != NULL)
  tmp = tmp->next;
  else
  break;
  }
  }*/

void	add_2_end_lstblocks(t_block *new, t_block **lst)
{
	t_block	*tmp;

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

t_block	*new_block(void)
{
	t_block	*new;

	if (!(new = (t_opt*)malloc(sizeof(t_opt))))
		return (NULL);
	if (!(new->tab = (int*)ft_memmalloc(sizeof(int) * 513)))
		return (NULL);
	new->next = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:29:55 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/12 14:20:43 by cpieri           ###   ########.fr       */
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

	if (!(new = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	if (!(new->tab = (uint32_t*)ft_memalloc(sizeof(uint32_t) * BLOCK_TAB_LEN)))
		return (NULL);
	new->next = NULL;
	return (new);
}

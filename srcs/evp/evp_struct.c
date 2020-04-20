/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evp_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 09:23:01 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/20 10:43:04 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evp/evp.h"

t_evp		*new_t_evp(uint8_t *pass, void *salt, void *key, void *vect)
{
	t_evp	*new;

	if (!(new = (t_evp*)malloc(sizeof(t_evp))))
		return (NULL);
	new->pass = pass;
	new->pass_len = ft_strlen((char*)new->pass);
	new->salt = (salt != NULL) ? salt : get_random();
	new->salt_len = ft_strlen((char*)new->salt);
	new->key = key;
	new->vect = vect;
	return (new);
}

void		print_evp(t_evp *k)
{
	char	*key;
	char	*vect;

	if (k == NULL)
	{
		ft_putendl("k is null");
		return ;
	}
	ft_putstr("pass:	");
	ft_putendl((char*)k->pass);
	ft_putstr("salt:	");
	ft_put64hexa(swap_uint64t(((uint64_t*)k->salt)[0]));
	ft_putchar('\n');
	ft_putstr("key:	");
	key = hex2sum(k->key, k->dk_len / 4);
	ft_putendl(key);
	ft_putstr("vect:	");
	vect = hex2sum(k->vect, k->iv_len / 4);
	ft_putendl(vect);
}

void		free_evp(t_evp **to_free)
{
	ft_memdel((void**)&((*to_free)->pass));
	ft_memdel((void**)&((*to_free)->salt));
	ft_memdel((void**)&((*to_free)->key));
	ft_memdel((void**)(to_free));
}

void		free_vevp(void **to_free)
{
	t_evp	**to_del;

	to_del = (t_evp**)to_free;
	ft_memdel((void**)&((*to_del)->pass));
	ft_memdel((void**)&((*to_del)->salt));
	ft_memdel((void**)&((*to_del)->key));
	ft_memdel((void**)(to_del));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:53:56 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/20 11:02:43 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/symmetric.h"
#include "ft_ssl.h"

uint8_t		*get_pass(const char *prompt)
{
	char	*pass;
	char	*conf_prompt;
	char	*conf_pass;

	conf_prompt = ft_strjoin("Verifying - ", prompt);
	pass = ft_strdup(getpass(prompt));
	conf_pass = getpass(conf_prompt);
	ft_memdel((void**)&conf_prompt);
	if (!pass || !conf_pass)
		exit_error_msg("getpass");
	if (ft_strcmp(conf_pass, pass) != 0)
	{
		ft_memdel((void**)&pass);
		exit_msg("Verifying Failure");
	}
	return ((uint8_t*)pass);
}

void		print_pbkdf(t_pbkdf *k)
{
	if (k == NULL)
	{
		ft_putendl("k is null");
		return ;
	}
	ft_putstr("pass:	");
	ft_putendl((char*)k->pass);
	ft_putstr("salt:	");
	ft_put64hexa(k->salt);
	ft_putchar('\n');
	ft_putstr("key:	");
	ft_put64hexa(k->key);
	ft_putchar('\n');
	ft_putstr("vect:	");
	ft_put64hexa(k->vect);
	ft_putchar('\n');
}

void		free_pbkdf(t_pbkdf **to_free)
{
	ft_memdel((void**)&((*to_free)->pass));
	ft_memdel((void**)&((*to_free)->salt));
	ft_memdel((void**)&((*to_free)->key));
	ft_memdel((void**)(to_free));
}

void		free_vpbkdf(void **to_free)
{
	t_pbkdf	**to_del;

	to_del = (t_pbkdf**)to_free;
	ft_memdel((void**)&((*to_del)->pass));
	ft_memdel((void**)&((*to_del)->salt));
	ft_memdel((void**)&((*to_del)->key));
	ft_memdel((void**)(to_del));
}

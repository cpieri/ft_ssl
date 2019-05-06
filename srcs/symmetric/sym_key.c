/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:53:56 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/06 15:07:17 by cpieri           ###   ########.fr       */
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
		exit_msg("getpass");
	if (ft_strcmp(conf_pass, pass) != 0)
	{
		ft_memdel((void**)&pass);
		exit_msg("Verifying Failure");
	}
	return ((uint8_t*)pass);
}

t_sym_key	*new_key(uint8_t *pass, uint64_t salt, uint64_t key)
{
	t_sym_key	*new;

	if (!(new = (t_sym_key*)malloc(sizeof(t_sym_key))))
		return (NULL);
	new->pass = pass;
	new->salt = salt;
	new->key = key;
	return (new);
}

void		free_sym_key(t_sym_key **to_free)
{
	ft_memdel((void**)&((*to_free)->pass));
	ft_memdel((void**)&((*to_free)->salt));
	ft_memdel((void**)&((*to_free)->key));
	ft_memdel((void**)(to_free));
}

void		free_vsym_key(void **to_free)
{
	t_sym_key	**to_del;

	to_del = (t_sym_key**)to_free;
	ft_memdel((void**)&((*to_del)->pass));
	ft_memdel((void**)&((*to_del)->salt));
	ft_memdel((void**)&((*to_del)->key));
	ft_memdel((void**)(to_del));
}
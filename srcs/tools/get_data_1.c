/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:54:47 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/20 10:24:39 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

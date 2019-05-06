/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:04:37 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/06 14:40:42 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "symmetric/symmetric.h"
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

static t_opt	*get_sym_args(const int ac, char **av, int now)
{
	t_opt		opt;
	t_sym_key	*k;
	uint8_t		*pass;

	(void)av, (void)now, (void)ac;
	opt = (t_opt){NULL, {0, 0, 0, 0, 0}, NULL};
	// while (now < ac)
	// {
	pass = get_pass("enter your password: ");
	printf("pass: %s\n",pass);
	k = new_key(pass, 0, 0);
	printf("k->pass: %s\n",k->pass);
	// 	now++;
	// }
	return (new_opt((t_flags){0,0,0,0,0}, NULL));
}

t_opt	*symmetric_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	new = get_sym_args(ac, av, now);
	add_to_end_lst(new, &opts);
	return (opts);
}
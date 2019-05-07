/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_usage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:15:38 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/07 16:15:07 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sym_usage(const char *opt)
{
	ft_putstr_fd("ft_ssl: Error options: ", 2);
	ft_putendl_fd(opt, 2);
	ft_putendl_fd("-e		Encrypt (default mode)", 2);
	ft_putendl_fd("-d		Decrypt", 2);
	ft_putstr_fd("-a		Base64 encode/decode,", 2);
	ft_putendl_fd(" depending on encryption flag", 2);
	ft_putendl_fd("-i <file>	Input file", 2);
	ft_putendl_fd("-o <file>	Output file", 2);
	ft_putendl_fd("-k <key>	Key in hex is the next arg", 2);
	ft_putendl_fd("-s <salt>	Salt in hex is the next arg", 2);
	ft_putendl_fd("-p <pass>	Password in ascii is the next arg", 2);
	ft_putendl_fd("-v <vect>	Init vector in ascii is the next arg", 2);
	exit(FAILURE);
}

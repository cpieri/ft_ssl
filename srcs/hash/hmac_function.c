/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:28:18 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/11 12:41:25 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symmetric/pbkdf.h"

void	hmac_sha256(uint8_t *pass, uint64_t salt, uint32_t c)
{
	void	*data_to_hash;
	void	*salty_pass;
	size_t	salty_pass_len;

	salty_pass = ft_memjoin(pass, &salt, ft_strlen((char*)pass), sizeof(uint64_t));
	salty_pass_len = ft_strlen((char*)pass) + sizeof(uint64_t);
	data_to_hash = ft_memjoin(salty_pass, &c, salty_pass_len, sizeof(uint32_t));
	ft_memput(data_to_hash, salty_pass_len + sizeof(uint32_t));
}
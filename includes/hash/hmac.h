/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 08:17:41 by cpieri            #+#    #+#             */
/*   Updated: 2019/12/31 12:24:18 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HMAC_H
# define HMAC_H

# include "hash.h"

# define I_PAD					0x36
# define O_PAD					0x5c
# define HMAC_BLOCK_SIZE_512	64
# define HMAC_BLOCK_SIZE_1024	128

void	*hmac_512_padding_key(void *key, size_t *key_len);
void	*hmac_512_xor_ipad(void const *key, size_t key_len);
void	*hmac_512_xor_opad(void const *key, size_t key_len);

void	*hmac_sha1(void *pwd, size_t pwd_len, void *key, size_t key_len);
void	*hmac_sha256(void *pwd, size_t pwd_len, void *key, size_t key_len);
void	*hmac_md5(void *pwd, size_t pwd_len, void *key, size_t key_len);

#endif
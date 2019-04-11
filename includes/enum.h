/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:34:08 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 16:11:35 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ENUM_H
# define ENUM_H

enum	e_algo
{
	e_hash = 1,
	e_cipher,
};

enum	e_cipher_flags
{
	e_base64_encode = 1,
	e_base64_decode,
	e_base64_inputf,
	e_base64_outputf,
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:34:08 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/15 14:19:15 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum	e_algo
{
	e_hash = 1,
	e_cipher,
};

enum	e_base64_flags
{
	e_base64_encode = 0x00000001,
	e_base64_decode = 0x00000010,
	e_base64_inputf = 0x00000100,
	e_base64_outputf = 0x00001000,
};

#endif

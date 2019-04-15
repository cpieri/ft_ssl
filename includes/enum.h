/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:34:08 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/15 11:34:32 by cpieri           ###   ########.fr       */
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
	e_base64_encode = 1,
	e_base64_decode = 2,
	e_base64_inputf = 3,
	e_base64_outputf = 4,
};

#endif

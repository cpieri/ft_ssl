/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:13:14 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/29 12:18:28 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	printing_base64(t_data *data, const char *name, t_flags flags)
{
	const char	*msg_print;

	msg_print = (const char *)data->data_2_print;
	(void)flags;
	ft_putstr(name);
	ft_putstr(": ");
	ft_putendl(msg_print);
}
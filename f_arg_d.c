/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arg_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 04:16:11 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/24 06:07:34 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_arg_d(va_list ap)
{
	int		n;
	char	*s;

	n = 0;
	s = ft_itoa(va_arg(ap, int));
	n = ft_strlen(s);
	ft_putstr_fd(s, 1);
	if (s)
		free(s);
	return (n);
}

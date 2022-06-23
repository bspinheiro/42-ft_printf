/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:27:17 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/23 11:50:00 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_printf(const char *str, ...)
{
	va_list	arg;

	va_start (arg, str);
	ft_putstr_fd((char *)str, 1);
	ft_putstr_fd(va_arg(arg, char *), 1);
	ft_putstr_fd(va_arg(arg, char *), 1);
	va_end (arg);
	return (0);
}

int
	main(void)
{
	ft_printf("bla\n", "ble\n", "blu\n");
	return (0);
}

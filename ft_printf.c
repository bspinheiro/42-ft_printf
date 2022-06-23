/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:27:17 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/22 19:12:18 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	ft_putchar(char c)
{
	write(1, &c, 1);
}

void
	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

int
	ft_printf(const char *str, ...)
{
	va_list	arg;

	va_start (arg, str);
	ft_putstr((char *)str);
	ft_putstr(va_arg(arg, char *));
	ft_putstr(va_arg(arg, char *));
	va_end (arg);
	return (0);
}

int
	main(void)
{
	ft_printf("bla\n", "ble\n", "blu\n");
	return (0);
}

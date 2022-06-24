/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:27:17 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/24 06:46:20 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TODO:
 * - read params
 * - sort params
 *   printf("", a, b, c)
 *   no ponteiro, unsigned long
 *	ft_putstr_fd(va_arg(arg, char *), 1);
 * */

#include "ft_printf.h"

static int
	ft_parse(char c, va_list ap)
{
	int		len;

	len = 0;
	if (c == 'c')
		len = f_arg_c(ap);
	if (c == 's')
		len = f_arg_s(ap);
	if (c == 'd')
		len = f_arg_d(ap);
	if (c == 'p')
		len = f_arg_p(ap);
	if (c == 'i')
		len = f_arg_i(ap);
	if (c == 'u')
		len = f_arg_u(ap);
	if (c == 'x')
		len = f_arg_x(ap);
	if (c == 'X')
		len = f_arg_X(ap);
	if (c == '%')
		len = f_arg_pc(ap);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		r;

	i = 0;
	r = 0;
	va_start (ap, str);
	if (!str)
		return (i);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && *ft_strchr("cspdiuxX%", str[i + 1]))
			r += ft_parse(str[++i], ap);
		else
		{
			r++;
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end (ap);
	/*
	puts(" ");
	ft_putnbr_fd(r, 1);
	puts("\n");
	*/
	return (r);
}

int
	main(void)
{
	ft_printf("blew %s%c %d\n", "blo", '!', -2035065302);
	printf("blew %s%c %d\n", "blo", '!', -2035065302);
	return (0);
}

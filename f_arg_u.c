/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arg_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 04:16:11 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/29 14:17:43 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_dc(int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_utoa(unsigned int n)
{
	long int	nb;
	size_t		l;
	char		*str;

	nb = n;
	l = ft_dc(n) - 1;
	str = ft_calloc(ft_dc(n) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

int	f_arg_u(int *counter, va_list ap)
{
	char	*s;

	s = ft_utoa(va_arg(ap, unsigned int));
	*counter += ft_strlen(s);
	ft_putstr_fd(s, 1);
	if (s)
		free(s);
	return (*counter);
}

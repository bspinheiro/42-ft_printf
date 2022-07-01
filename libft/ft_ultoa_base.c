/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:37:29 by bda-silv          #+#    #+#             */
/*   Updated: 2022/07/01 14:38:45 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long n, unsigned int base)
{
	char		*b;
	int			len;
	char		*str;

	if (base <= 0)
		return (NULL);
	len = ft_nbrlen(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	b = ft_substr("0123456789abcdefghijklmnopqrstuvwxyz", 0, base);
	if (!b)
		return (NULL);
	if (n == 0)
		str[0] = b[0];
	while (len > 0)
	{
		str[--len] = b[n % base];
		n /= base;
	}
	return (str);
}

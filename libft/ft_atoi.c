/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:19:53 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/18 15:35:28 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int		i;
	int		signal;
	int		number;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	signal = 1;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	number = 0;
	while (ft_isdigit((int)str[i]))
		number = (number * 10) + (str[i++] - '0');
	return ((int)(number * signal));
}

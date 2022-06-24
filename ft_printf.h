/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:11:48 by bda-silv          #+#    #+#             */
/*   Updated: 2022/06/24 06:46:14 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h> // TODO: Remove this header before Evaluation

int	ft_printf(const char *str, ...);
int	f_arg_c(va_list ap);
int	f_arg_s(va_list ap);
int	f_arg_d(va_list ap);
int	f_arg_p(va_list ap);
int	f_arg_i(va_list ap);
int	f_arg_u(va_list ap);
int	f_arg_x(va_list ap);
int	f_arg_X(va_list ap);
int	f_arg_pc(va_list ap);

#endif

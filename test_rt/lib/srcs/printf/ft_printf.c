/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:07:48 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/03 18:10:04 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	token_converter(va_list args, const char token, int fd)
{
	int	i;

	i = 1;
	if (token == 'c')
		ft_putchar_fd(va_arg(args, int), fd);
	else if (token == 's')
		i = print_s(va_arg(args, char *), fd);
	else if (token == 'p')
	{
		write(fd, "0x", 2);
		i = print_p(va_arg(args, unsigned long long), fd);
	}
	else if (token == 'i' || token == 'd')
		i = print_id(va_arg(args, int), fd);
	else if (token == 'u')
		i = print_u(va_arg(args, unsigned int), fd);
	else if (token == 'x' || token == 'X')
		i = print_x(va_arg(args, unsigned int), fd, token);
	else if (token == '%')
		ft_putchar_fd('%', fd);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += token_converter(args, str[i + 1], 1);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

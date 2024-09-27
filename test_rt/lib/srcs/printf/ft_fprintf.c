/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:00:34 by hmorand           #+#    #+#             */
/*   Updated: 2024/05/13 20:00:46 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	ft_fprintf(int fd, const char *str, ...)
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
			len += token_converter(args, str[i + 1], fd);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], fd);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

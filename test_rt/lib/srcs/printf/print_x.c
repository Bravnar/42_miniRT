/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:05:57 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/03 18:10:38 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static int	count_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n || len == 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	print_x(unsigned int n, int fd, const char token)
{
	int	len;

	len = count_hexlen(n);
	if (n > 15)
		print_x(n / 16, fd, token);
	if (token == 'x')
	{
		if (write(fd, &"0123456789abcdef"[n % 16], 0) < 0)
			return (-1);
		write(fd, &"0123456789abcdef"[n % 16], 1);
	}
	else if (token == 'X')
	{
		if (write(fd, &"0123456789ABCDEF"[n % 16], 0) < 0)
			return (-1);
		write(fd, &"0123456789ABCDEF"[n % 16], 1);
	}
	return (len);
}

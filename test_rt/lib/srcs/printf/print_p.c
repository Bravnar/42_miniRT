/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:05:54 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/03 18:10:26 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static int	count_hexlen(unsigned long long n)
{
	int	len;

	len = 2;
	while (n || len == 2)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	print_p(unsigned long long n, int fd)
{
	int				len;

	len = count_hexlen(n);
	if (n > 15)
		print_p(n / 16, fd);
	if (write(fd, &"0123456789abcdef"[n % 16], 0) < 0)
		return (-1);
	write(fd, &"0123456789abcdef"[n % 16], 1);
	return (len);
}

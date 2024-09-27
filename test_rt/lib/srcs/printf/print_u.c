/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:06:04 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/03 18:10:34 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static int	count_unslen(unsigned int n)
{
	int	len;

	len = 0;
	while (n || len == 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	print_u(unsigned int n, int fd)
{
	int	len;

	len = count_unslen(n);
	if (n > 9)
		print_u(n / 10, fd);
	if (write(fd, &"0123456789"[n % 10], 0) < 0)
		return (-1);
	write(fd, &"0123456789"[n % 10], 1);
	return (len);
}

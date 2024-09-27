/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:06:00 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/03 18:10:16 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static int	count_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	print_id(int n, int fd)
{
	unsigned int	nbr;
	int				len;

	len = count_numlen(n);
	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > 9)
		print_id(nbr / 10, fd);
	if (write(1, &"0123456789"[nbr % 10], 0) < 0)
		return (-1);
	write(1, &"0123456789"[nbr % 10], 1);
	return (len);
}

/* 
int main(int ac, char **av)
{
	(void) 	ac;
	int		len;

	len = print_num(atoi(av[1]), 1);
	printf("\n%d length", len);
	return (0);
} */

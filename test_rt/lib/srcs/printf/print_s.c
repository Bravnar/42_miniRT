/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:06:02 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/03 18:10:31 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	print_s(const char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
	{
		print_s("(null)", fd);
		return (6);
	}
	while (str[i])
		ft_putchar_fd(str[i++], fd);
	return (i);
}

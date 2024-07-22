/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:50:36 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/07 10:09:49 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (is_whitespace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9') || *nptr == 0)
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

/* #include <stdio.h>

int	main(int ac, char **av)
{
	(void) ac;
	int number = ft_atoi(av[1]);
	int number_2 = atoi(av[1]);

	printf("Test with ft_atoi: %d\n", number);
	printf("Test with atoi: %d\n", number_2);
	return (0);
} */
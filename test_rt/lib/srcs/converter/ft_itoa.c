/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:51:15 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/07 09:55:20 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static int	count_digits(int numb)
{
	int	i;

	if (numb == 0)
		return (1);
	i = 0;
	if (numb < 0)
		i++;
	while (numb)
	{
		numb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;

	i = count_digits(n);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	if (!n)
		result[0] = '0';
	result[i] = '\0';
	while (n)
	{
		if (n < 0)
			result[i - 1] = '0' + -(n % 10);
		else
			result[i - 1] = '0' + n % 10;
		n /= 10;
		i--;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(int ac, char **av)
{
	(void) ac;
	
	int num = ft_atoi(av[1]);
	char *numb = ft_itoa(num);
	ft_putstr_fd(numb, 1);
}
 */
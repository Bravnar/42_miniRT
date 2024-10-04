/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:59:30 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/07 10:16:31 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

/* #include <stdio.h>

void	modify_string(unsigned int index, char *c)
{
	(void) index;
	*c = *c + ' ';
}

int	main(void)
{
	char	test_string[] = "HELLO, WORLD";
	printf("Original String: %s\n", test_string);
	ft_striteri(test_string, modify_string);
	printf("Modified string: %s\n", test_string);
	return (0);
}
 */
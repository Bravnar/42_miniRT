/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:18:01 by codespace         #+#    #+#             */
/*   Updated: 2023/11/07 09:55:33 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/* #include <stdio.h>
int main(int ac, char **av)
{
	(void) ac;
	char *input = av[1];
	printf("The resulting letter is %c\n", ft_toupper(input[0]));
	return (0);
} */
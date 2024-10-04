/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:31:42 by codespace         #+#    #+#             */
/*   Updated: 2023/11/07 09:55:26 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/* #include <stdio.h>
int main(int ac, char **av)
{
	(void) ac;
	char *input = av[1];
	printf("The changed letter is %c\n", ft_tolower(input[0]));
	return (0);	
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:34:32 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 10:37:31 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_mrt	*mrt;

	if (ac < 2)
		err_template(M_NO_ARGS, av[0]);
	if (ac == 2)
	{
		mrt = initialize(av[1]);
		if (!mrt)
			exit(1);
		setup_loop(mrt);
		free(mrt);
	}
	return (0);
}

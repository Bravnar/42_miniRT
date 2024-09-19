/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:34:32 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 16:20:14 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_mrt	*mrt;

	if (ac < 2)
		err_template(M_NO_ARGS, ft_strdup(av[0]), NULL);
	if (ac == 2)
	{
		if (!check_file_name(av[1]))
			err_template(M_WRONG_EXT, av[1], NULL);
		mrt = initialize(av[1]);
		if (!mrt)
			exit(1);
		setup_loop(mrt);
		exit(0);
	}
	return (0);
}

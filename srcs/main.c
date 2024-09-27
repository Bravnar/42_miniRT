/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:32:54 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/20 10:32:54 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_mrt	*mrt;

	if (ac < 2)
		err_template(M_NO_ARGS, av[0]);
	else if (ac == 2)
	{
		mrt = initialize(av[1]);
		if (!mrt)
			exit(1);
		setup_loop(mrt);
		free_rt(mrt);
	}
	return (0);
}

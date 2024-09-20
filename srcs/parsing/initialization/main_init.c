/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:46:39 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/20 09:17:06 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_mrt	*initialize(char *filename)
{
	t_mrt		*mrt;
	t_errors	*err;
	
	mrt = ft_calloc(1, sizeof(t_mrt));
	if (!mrt)
		return (NULL);
	mrt->map = create_map(filename);
	err = *get_errors();
	if (err)
	{
		printf("pre-fetch errors ----------------:\n");
		print_errors();
		exit(1);
	}
	fill_map();
	err = *get_errors();
	if (err)
	{
		printf("post-fetch errors ----------------:\n");
		print_errors();
		exit(1);
	}
	init_mlx(&mrt->mlx);
	return (mrt);
}

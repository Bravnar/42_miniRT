/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:06:13 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/20 10:06:13 by hmorand          ###   ########.ch       */
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
		clean_post_fetch(mrt);
	}
	fill_map();
	err = *get_errors();
	if (err)
	{
		printf("post-fetch errors ----------------:\n");
		print_errors();
		clean_post_fetch(mrt);
	}
	init_mlx(&mrt->mlx);
	return (mrt);
}

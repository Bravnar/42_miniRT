/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:58:22 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/19 15:58:38 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_mrt	*initialize(char *filename)
{
	static t_mrt	*mrt;

	if (mrt)
		return (mrt);
	if (!filename)
		return (NULL);
	mrt = ft_calloc(1, sizeof(t_mrt));
	if (!mrt)
		return (NULL);
	mrt->map = create_map(filename);
	init_mlx(&mrt->mlx);
	return (mrt);
}

t_mrt	*get_mrt(void)
{
	static t_mrt	*mrt;

	if (!mrt)
		mrt = initialize(NULL);
	return (mrt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:46:39 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 12:23:08 by smuravye         ###   ########.fr       */
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
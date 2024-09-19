/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:46:39 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 10:46:40 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_mrt	*initialize(char *filename)
{
	t_mrt	*mrt;

	mrt = ft_calloc(1, sizeof(t_mrt));
	if (!mrt)
		return (NULL);
	mrt->map = create_map(filename);
	init_mlx(&mrt->mlx);
	return (mrt);
}

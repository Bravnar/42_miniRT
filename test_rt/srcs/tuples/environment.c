/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 25/07/2024 09:40:36 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:06:27 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_env	env_new(t_tup wind, t_tup gravity)
{
	t_env	new;

	new.wind = wind;
	new.gravity = gravity;
	return (new);
}

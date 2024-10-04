/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 25/07/2024 09:40:36 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:06:55 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_proj	tick(t_env env, t_proj proj)
{
	t_proj	new;

	new.position = tuple_add(proj.position, proj.velocity);
	new.velocity = tuple_add(proj.velocity, tuple_add(env.gravity, env.wind));
	return (new);
}

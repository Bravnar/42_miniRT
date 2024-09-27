/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:35:47 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 10:35:49 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_rwin(t_rwin *win)
{
	ft_bzero(win, sizeof(t_rwin));
}

void	init_amb(t_amb *amb)
{
	ft_bzero(amb, sizeof(t_amb));
}

void	init_cam(t_cam *cam)
{
	ft_bzero(cam, sizeof(t_cam));
}

void	init_light(t_light *light)
{
	ft_bzero(light, sizeof(t_light));
}

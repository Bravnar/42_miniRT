/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:43:16 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 10:43:17 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_view_cam(t_view_cam cam)
{
	printf("hsize: %f\n", cam.hsize);
	printf("vsize: %f\n", cam.vsize);
	printf("fov: %.2f\n", cam.fov);
	printf("aspect ratio: %f\n", cam.aspect);
	printf("half_view: %.2f\n", cam.half_view);
	printf("half_width: %.2f\n", cam.half_width);
	printf("half_height: %.2f\n", cam.half_height);
	printf("pixel_size: %.2f\n", cam.pixel_size);
	printf("tranform-------------:\n");
	print_matrix(cam.transf_matrix, 4);
}

t_world	create_world(void)
{
	t_world	w;

	w.light = get_map()->light;
	w.shapes = get_map()->obj_list;
	return (w);
}

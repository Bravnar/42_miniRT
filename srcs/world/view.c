/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:02:46 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/03 09:03:14 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * Generates a ray for a given pixel in the camera's view.
 *
 * @param cam The camera view parameters.
 * @param px The x-coordinate of the pixel.
 * @param py The y-coordinate of the pixel.
 * @return A ray originating from the camera and passing through
 * the specified pixel.
 */
t_ray	ray_for_pixel(t_view_cam cam, double px, double py)
{
	t_cam_ray	r;
	t_tup		origin;
	t_tup		direction;

	r.xoffset = (px + 0.5) * cam.pixel_size;
	r.yoffset = (py + 0.5) * cam.pixel_size;
	r.world_x = cam.half_width - r.xoffset;
	r.world_y = cam.half_height - r.yoffset;
	r.pixel = matrix_mult_tup(inverse(cam.transf_matrix, 4),
			point(r.world_x, r.world_y, -1));
	origin = matrix_mult_tup(inverse(cam.transf_matrix, 4),
			point(0, 0, 0));
	direction = vector_norm(tuple_sub(r.pixel, origin));
	return (ray_new(origin, direction));
}

/**
 * @brief Calculates the pixel size for the given camera view.
 *
 * This function computes the size of each pixel in the camera's view based on
 * the camera's properties and settings. The calculated pixel size is used for
 * rendering the scene accurately.
 *
 * @param cam A pointer to the camera view structure containing the necessary
 *            properties and settings for the calculation.
 */
void	calc_pixel_size(t_view_cam *cam)
{
	cam->half_view = tan(cam->fov / 2);
	cam->aspect = cam->hsize / cam->vsize;
	if (cam->aspect >= 1)
	{
		cam->half_width = cam->half_view;
		cam->half_height = cam->half_view / cam->aspect;
	}
	else
	{
		cam->half_width = cam->half_view * cam->aspect;
		cam->half_height = cam->half_view;
	}
	cam->pixel_size = (cam->half_width * 2) / cam->hsize;
}

/**
 * @brief Computes the view transformation matrix.
 *
 * This function calculates the view transformation matrix based on the given
 * parameters. The view transformation matrix is used to transform coordinates
 * from world space to camera space.
 *
 * @param from The position of the camera in world space.
 * @param forward The direction in which the camera is pointing.
 * @param up The up direction vector for the camera.
 * @return The view transformation matrix.
 */
t_matrix	view_transform(t_tup from, t_tup forward, t_tup up)
{
	t_tup		upn;
	t_tup		left;
	t_tup		true_up;
	t_matrix	orientation;

	upn = vector_norm(up);
	left = vector_cross(forward, upn);
	true_up = vector_cross(left, forward);
	orientation = identity();
	orientation.m[0][0] = left.x;
	orientation.m[0][1] = left.y;
	orientation.m[0][2] = left.z;
	orientation.m[1][0] = true_up.x;
	orientation.m[1][1] = true_up.y;
	orientation.m[1][2] = true_up.z;
	orientation.m[2][0] = -forward.x;
	orientation.m[2][1] = -forward.y;
	orientation.m[2][2] = -forward.z;
	return (matrix_mult(orientation,
			translation_matrix(-from.x, -from.y, -from.z)));
}

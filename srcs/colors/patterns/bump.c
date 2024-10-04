/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:51:57 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/02 14:54:51 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// Hash function to generate a pseudo-random number from an integer
unsigned int	hash(unsigned int x)
{
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;
	return (x);
}

/**
 * @brief Generates a simple noise value based on a 3D point.
 *
 * This function computes a noise value for a given 3D point using a combination
 * of hashing and interpolation. The noise value is calculated
 * by first determining the integer coordinates of the point,
 * then computing the fractional part, and finally interpolating
 * between hashed values of the surrounding points.
 *
 * @param p A 3D point represented as a t_tup structure.
 * @return A double representing the noise value at the given point.
 */

double	simple_noise(t_tup p)
{
	int		i[3];
	t_tup	f;
	t_tup	u;
	double	n[8];

	i[0] = (int)floor(p.x);
	i[1] = (int)floor(p.y);
	i[2] = (int)floor(p.z);
	f = point(p.x - i[0], p.y - i[1], p.z - i[2]);
	u = point(f.x * f.x * (3.0 - 2.0 * f.x), f.y * f.y * (3.0 - 2.0 * f.y),
			f.z * f.z * (3.0 - 2.0 * f.z));
	n[0] = (double)hash(hash(hash(i[0]) + i[1]) + i[2]) / UINT_MAX;
	n[1] = (double)hash(hash(hash(i[0]) + i[1]) + i[2] + 1) / UINT_MAX;
	n[2] = (double)hash(hash(hash(i[0]) + i[1] + 1) + i[2]) / UINT_MAX;
	n[3] = (double)hash(hash(hash(i[0]) + i[1] + 1) + i[2] + 1) / UINT_MAX;
	n[4] = (double)hash(hash(hash(i[0] + 1) + i[1]) + i[2]) / UINT_MAX;
	n[5] = (double)hash(hash(hash(i[0] + 1) + i[1]) + i[2] + 1) / UINT_MAX;
	n[6] = (double)hash(hash(hash(i[0] + 1) + i[1] + 1) + i[2]) / UINT_MAX;
	n[7] = (double)hash(hash(hash(i[0] + 1) + i[1] + 1) + i[2] + 1) / UINT_MAX;
	return (n[0] * (1 - u.x) * (1 - u.y) * (1 - u.z) \
		+ n[1] * (1 - u.x) * (1 - u.y) * u.z \
		+ n[2] * (1 - u.x) * u.y * (1 - u.z) + n[3] * (1 - u.x) * u.y * u.z \
		+ n[4] * u.x * (1 - u.y) * (1 - u.z) + n[5] * u.x * (1 - u.y) * u.z \
		+ n[6] * u.x * u.y * (1 - u.z) + n[7] * u.x * u.y * u.z);
}

/**
 * @brief Perturbs the normal vector at a given point on
 * an object using a specified pattern.
 *
 * @param obj Pointer to the object whose normal vector is to be perturbed.
 * @param p The point on the object where the normal vector is to be perturbed.
 * @param normal The original normal vector at the point.
 * @param pat The pattern used to perturb the normal vector.
 * @return The perturbed normal vector.
 */
t_tup	perturb_normal(t_obj *obj, t_tup p, t_tup normal, t_pattern pat)
{
	t_tup	offset;
	t_tup	noise;

	(void) obj;
	noise.x = simple_noise(point(p.x * pat.scale,
				p.y * pat.scale, p.z * pat.scale));
	noise.y = simple_noise(point((p.x + 0.0001) * pat.scale,
				p.y * pat.scale, p.z * pat.scale));
	noise.z = simple_noise(point(p.x * pat.scale,
				(p.y + 0.0001) * pat.scale, p.z * pat.scale));
	offset = vector((noise.y - noise.x) / 0.0001,
			(noise.z - noise.x) / 0.0001, 0);
	return (vector_norm(tuple_add(normal,
				vector_scalar_mult(offset, pat.noise))));
}

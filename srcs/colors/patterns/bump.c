#include "main.h"

// Simple hash function
unsigned int	hash(unsigned int x)
{
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;
	return (x);
}

// Simple noise function
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

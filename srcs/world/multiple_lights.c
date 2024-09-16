#include "main.h"

t_tup	light_vector_curr(t_tup point, t_light *curr)
{
	return (vector_norm(tuple_sub(curr->point, point)));
}

double	calculate_shadow_intensity_multi(t_world world, t_tup point, t_light *light)
{
	t_ray	shadow_ray;
	t_inter	*shadow_intersections;
	double	shadow_intensity;
	double 	distance_to_light;
	t_inter *current;

	shadow_ray = ray_new(point, light_vector_curr(point, light));
	shadow_intersections = intersect_world(world, shadow_ray);
	shadow_intensity = 1.0;
	current = shadow_intersections;
	distance_to_light = vector_mag(tuple_sub(light->point, point));
	while (current != NULL && !equal(shadow_intensity, 0.0))
	{
		if (current->i.t > 0 && current->i.t < distance_to_light)
		{
			if (current->i.shape->material.transparency == 0)
				shadow_intensity = 0;
			else
				shadow_intensity *= current->i.shape->material.transparency;
		}
		current = current->next;
	}
	free_inter_nodes(shadow_intersections);
	return (shadow_intensity);
}

t_color	accumulate_lights(t_world w, t_comps comps)
{
	t_color	total_surface;
	t_color	surface;
	t_light	*curr_light;
	double	shadow_intensity;
	t_tup	views[2];

	views[0] = comps.eyev;
	views[1] = comps.normalv;
	total_surface = black();
	curr_light = w.light;
	while (curr_light)
	{
		shadow_intensity = calculate_shadow_intensity_multi(w, comps.over_point, curr_light);
		surface = lighting(comps.obj, comps.point, views, shadow_intensity);
		total_surface = color_add(total_surface, surface);
		curr_light = curr_light->next;
	}
	return (total_surface);
}

t_color	iterative_shade_hit_multi(t_world w, t_comps comps, int remaining)
{
	t_color	total_surface;
	t_color	reflected;
	t_color	refracted;

	total_surface = accumulate_lights(w, comps);
	reflected = reflected_color(w, comps, remaining);
	refracted = refracted_color(w, comps, remaining);
	return (with_reflect(comps, total_surface, reflected, refracted));
}
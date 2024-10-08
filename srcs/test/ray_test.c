/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:05:45 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/18 10:05:45 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_inter(t_inter *got, t_inter *exp, char *tn)
{
	printf("----------------------------------\
----------------\n");
	if (equal_inter(&got, &exp))
		printf(BOLD_GREEN"Test passed - %s\n"RESET, tn);
	else
	{
		printf(BOLD_RED"Test failed - %s\n"RESET, tn);
		printf(BOLD_WHITE"Expected:\n"RESET);
		print_inter(&exp);
		printf(BOLD_WHITE"Got:\n"RESET);
		print_inter(&got);
	}
	printf("\n");
}

void	ray_test_1(void)
{
	t_ray	r;
	t_obj	*shape;
	t_inter	*got;
	t_inter	*expected;

	shape = (t_obj *) sphere(0);
	r = ray_new(point(0, 0, -5), vector(0, 0, 1));
	got = shape->local_intersect(r, shape);
	expected = new_inter(2, shape, 4.0, 6.0);
	test_inter(got, expected, "Ray intersects sphere at two points");
	free_inter_nodes(got);
	free_inter_nodes(expected);
	r = ray_new(point(0, 1, -5), vector(0, 0, 1));
	got = shape->local_intersect(r, shape);
	expected = new_inter(2, shape, 5.0, 5.0);
	test_inter(got, expected, "Ray intersects sphere at tangent");
	free_inter_nodes(got);
	free_inter_nodes(expected);
	r = ray_new(point(0, 2, -5), vector(0, 0, 1));
	got = shape->local_intersect(r, shape);
	expected = new_inter(0, shape);
	test_inter(got, expected, "Ray misses sphere");
	free_inter_nodes(got);
	free_inter_nodes(expected);
	free(shape);
}

void	ray_test_2(void)
{
	t_ray	r;
	t_obj	*shape;
	t_inter	*got;
	t_inter	*expected;

	shape = (t_obj *) sphere(0);
	r = ray_new(point(0, 0, 0), vector(0, 0, 1));
	got = shape->local_intersect(r, shape);
	expected = new_inter(2, shape, -1.0, 1.0);
	test_inter(got, expected, "Ray originates inside sphere");
	free_inter_nodes(got);
	free_inter_nodes(expected);
	r = ray_new(point(0, 0, 5), vector(0, 0, 1));
	got = shape->local_intersect(r, shape);
	expected = new_inter(2, shape, -6.0, -4.0);
	test_inter(got, expected, "Sphere is behind ray");
	free_inter_nodes(got);
	free_inter_nodes(expected);
	free(shape);
}

void	ray_test_battery(void)
{
	printf(BOLD_YELLOW"Ray-sphere intersections battery\n"RESET);
	ray_test_1();
	ray_test_2();
}

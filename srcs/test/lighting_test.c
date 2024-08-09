#include "main.h"

void	test_lighting(t_tup eye_v, t_tup normal_v, t_color e, char *tn)
{
	t_color		result;

	result = lighting(mat_default(), point(0, 0, 0), eye_v, normal_v);
	printf("--------------------------------------------\
-----------------------\n");
	if (equal_color(result, e))
		printf(BOLD_GREEN"Test passed - %s\n"RESET, tn);
	else
	{
		printf(BOLD_RED"Test failed - %s\n"RESET, tn);
		printf("Expected:\t(%f, %f, %f, %f)\n", e.r / 255,
			e.g / 255, e.b / 255, e.t / 255);
		printf("Got:\t\t(%f, %f, %f, %f)\n", result.r / 255,
			result.g / 255, result.b / 255, result.t);
	}
	printf("\n");
}

void	lighting_test_1(void)
{
	t_tup		eye_v;
	t_tup		normal_v;
	t_light		*light;

	light = new_light_node(point(0, 0, -10), 1,
			color(255, 255, 255), color(255, 255, 255));
	add_light_node_front(light, &get_scene()->light);
	eye_v = vector(0, 0, -1);
	normal_v = vector(0, 0, -1);
	test_lighting(eye_v, normal_v,
		color(1.9 * 255, 1.9 * 255, 1.9 * 255),
		"Eye between light and surface");
	eye_v = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	normal_v = vector(0, 0, -1);
	test_lighting(eye_v, normal_v, color(255, 255, 255),
		"Eye between light and surface, eye offset 45 degrees");
	remove_first_light(&get_scene()->light);
}

void	lighting_test_2(void)
{
	t_tup		eye_v;
	t_tup		normal_v;
	t_light		*light;

	light = new_light_node(point(0, 10, -10), 1,
			color(255, 255, 255), color(255, 255, 255));
	add_light_node_front(light, &get_scene()->light);
	eye_v = vector(0, 0, -1);
	normal_v = vector(0, 0, -1);
	test_lighting(eye_v, normal_v,
		color(0.736396 * 255, 0.736396 * 255, 0.736396 * 255),
		"Light source offset by 45 degrees");
	eye_v = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	normal_v = vector(0, 0, -1);
	test_lighting(eye_v, normal_v,
		color(1.636396 * 255, 1.636396 * 255, 1.636396 * 255),
		"Lighting with eye in the path of reflection");
	remove_first_light(&get_scene()->light);
}

void	lighting_test_3(void)
{
	t_tup		eye_v;
	t_tup		normal_v;
	t_light		*light;

	light = new_light_node(point(0, 0, 10), 1,
			color(255, 255, 255), color(255, 255, 255));
	add_light_node_front(light, &get_scene()->light);
	eye_v = vector(0, 0, -1);
	normal_v = vector(0, 0, -1);
	test_lighting(eye_v, normal_v, color(25.5, 25.5, 25.5),
		"Lighting with light behind the surface");
	remove_first_light(&get_scene()->light);
	light = new_light_node(point(0, 0, -10), 1,
			color(510, 510, 510), color(510, 510, 510));
	add_light_node_front(light, &get_scene()->light);
	eye_v = vector(0, 0, -1);
	normal_v = vector(0, 0, -1);
	test_lighting(eye_v, normal_v, color(2.8 * 255, 2.8 * 255, 2.8 * 255),
		"Lighting with intense light source");
	remove_first_light(&get_scene()->light);
}

void	lighting_test_battery(void)
{
	printf(BOLD_YELLOW"Lighting test battery\n"RESET);
	lighting_test_1();
	lighting_test_2();
	lighting_test_3();
}

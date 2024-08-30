#include "main.h"

void	test_lighting(t_tup views[2], t_color e, char *tn, bool in_shadow)
{
	t_color		result;

	result = lighting((t_obj *)sphere(0), point(0, 0, 0), views, in_shadow);
	printf("--------------------------------------------\
-----------------------\n");
	if (equal_color(result, e))
		printf(BOLD_GREEN"Test passed - %s\n"RESET, tn);
	else
	{
		printf(BOLD_RED"Test failed - %s\n"RESET, tn);
		printf("Expected:\t(%.8f, %.8f, %.8f)\n", e.r / 255,
			e.g / 255, e.b / 255);
		printf("Got:\t\t(%.8f, %.8f, %.8f)\n", result.r / 255,
			result.g / 255, result.b / 255);
	}
	printf("\n");
}

void	lighting_test_1(void)
{
	t_tup		views[2];
	t_light		*light;

	light = new_light_node(point(0, 0, -10), 1,
			color(255, 255, 255), color(255, 255, 255));
	add_light_node_front(light, &get_scene()->light);
	views[0] = vector(0, 0, -1);
	views[1] = vector(0, 0, -1);
	test_lighting(views, color(1.9 * 255, 1.9 * 255, 1.9 * 255),
		"Eye between light and surface", false);
	views[0] = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	views[1] = vector(0, 0, -1);
	test_lighting(views, color(255, 255, 255),
		"Eye between light and surface, eye offset 45 degrees", false);
	remove_first_light(&get_scene()->light);
}

void	lighting_test_2(void)
{
	t_tup		views[2];
	t_light		*light;

	light = new_light_node(point(0, 10, -10), 1,
			color(255, 255, 255), color(255, 255, 255));
	add_light_node_front(light, &get_scene()->light);
	views[0] = vector(0, 0, -1);
	views[1] = vector(0, 0, -1);
	test_lighting(views, color(0.7363961 * 255,
			0.7363961 * 255, 0.7363961 * 255),
		"Light source offset by 45 degrees", false);
	views[0] = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	views[1] = vector(0, 0, -1);
	test_lighting(views,
		color(1.6363961 * 255, 1.6363961 * 255, 1.6363961 * 255),
		"Lighting with eye in the path of reflection", false);
	remove_first_light(&get_scene()->light);
	light = new_light_node(point(0, 0, 10), 1,
			color(255, 255, 255), color(255, 255, 255));
	add_light_node_front(light, &get_scene()->light);
	views[0] = vector(0, 0, -1);
	views[1] = vector(0, 0, -1);
	test_lighting(views, color(25.5, 25.5, 25.5),
		"Lighting with light behind the surface", false);
	remove_first_light(&get_scene()->light);
}

void	lighting_test_3(void)
{
	t_tup		views[2];
	t_light		*light;

	light = new_light_node(point(0, 0, -10), 1,
			color(510, 510, 510), color(510, 510, 510));
	add_light_node_front(light, &get_scene()->light);
	views[0] = vector(0, 0, -1);
	views[1] = vector(0, 0, -1);
	test_lighting(views, color(2.8 * 255, 2.8 * 255, 2.8 * 255),
		"Lighting with intense light source", false);
	remove_first_light(&get_scene()->light);
	light = new_light_node(point(0, 0, -10), 1,
			color(255, 255, 255), color(255, 255, 255));
	add_light_node_front(light, &get_scene()->light);
	views[0] = vector(0, 0, -1);
	views[1] = vector(0, 0, -1);
	test_lighting(views, color(25.5, 25.5, 25.5),
		"Lighting with shadows", true);
	remove_first_light(&get_scene()->light);
}

void	lighting_test_battery(void)
{
	printf(BOLD_YELLOW"Lighting test battery\n"RESET);
	lighting_test_1();
	lighting_test_2();
	lighting_test_3();
}

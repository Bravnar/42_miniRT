#include "main.h"

void	test_hit(t_intersection got, t_intersection exp, char* tn)
{
	printf("-------------------------------\
--------------------------\n");
	if (got.t == exp.t)
		printf(BOLD_GREEN"Test passed - %s\n"RESET, tn);
	else
	{
		printf(BOLD_RED"Test failed - %s\n"RESET, tn);
		printf(BOLD_WHITE"Expected:\n"RESET);
		print_intersection(exp);
		printf(BOLD_WHITE"Got:\n"RESET);
		print_intersection(got);
	}
	printf("\n");
}

void	hit_test_1(void)
{
	t_obj			*s;
	t_inter			inter;
	t_intersection	got;

	s = (t_obj *) sphere();
	inter = sort_inter(new_inter(2, s, 1.0, 2.0));
	got = hit(inter);
	test_hit(got, intersection(1, s),
		"Hit when all intersections have positive t");
	free_inter(inter);
	inter = sort_inter(new_inter(2, s, -1.0, 1.0));
	got = hit(inter);
	test_hit(got, intersection(1, s),
		"Hit when some intersections have negative t");
	free_inter(inter);
	inter = sort_inter(new_inter(2, s, -2.0, -1.0));
	got = hit(inter);
	test_hit(got, intersection(-1, s),
		"Hit when all intersections have negative t");
	free_inter(inter);
	free(s);
}

void	hit_test_2(void)
{
	t_obj			*s;
	t_inter			inter;
	t_intersection	got;

	s = (t_obj *) sphere();
	inter = sort_inter(new_inter(4, s, 5.0, 7.0, -3.0, 2.0));
	got = hit(inter);
	test_hit(got, intersection(2, s),
		"Hit when some intersections are positive");
	free_inter(inter);
	free(s);
}

void	hit_test_battery(void)
{
	printf(BOLD_YELLOW"Hit test battery\n"RESET);
	hit_test_1();
	hit_test_2();
}

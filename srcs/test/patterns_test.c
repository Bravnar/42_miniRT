#include "main.h"

void	test_stripe_pattern(t_tup p, t_color exp, char *tn)
{
	t_color	result;
	t_obj	*sp;
	t_tup	views[2];

	views[0] = vector(0, 0, -1);
	views[1] = vector(0, 0, -1);
	sp = (t_obj *) sphere(0);
	sp->material.pattern = pattern(white(), black(), STRIPE, identity());
	sp->material.diffuse = 0;
	sp->material.specular = 0;
	sp->material.amb = 1;
	result = lighting(sp, p, views, false);
	printf("--------------------------------------------\n");
	if (equal_color(result, exp))
		printf(BOLD_GREEN "Test passed - %s\n" RESET, tn);
	else
	{
		printf(BOLD_RED "Test failed - %s\n" RESET, tn);
		printf("Expected:\t(%.3f, %.3f, %.3f)\n", exp.r / 255,
			exp.g / 255, exp.b / 255);
		printf("Got:\t\t(%.3f, %.3f, %.3f)\n", result.r / 255,
			result.g / 255, result.b / 255);
	}
	free(sp);
	printf("\n");
}

void	test_gradient_pattern(t_tup p, t_color exp, char *tn)
{
	t_color	result;
	t_obj	*sp;
	t_tup	views[2];

	views[0] = vector(0, 0, -1);
	views[1] = vector(0, 0, -1);
	sp = (t_obj *)sphere(0);
	sp->material.pattern = pattern(white(), black(), GRADIENT, identity());
	sp->material.diffuse = 0;
	sp->material.specular = 0;
	sp->material.amb = 1;
	result = lighting(sp, p, views, false);
	printf("--------------------------------------------\n");
	if (equal_color(result, exp))
		printf(BOLD_GREEN "Test passed - %s\n" RESET, tn);
	else
	{
		printf(BOLD_RED "Test failed - %s\n" RESET, tn);
		printf("Expected:\t(%.3f, %.3f, %.3f)\n", exp.r / 255,
			exp.g / 255, exp.b / 255);
		printf("Got:\t\t(%.3f, %.3f, %.3f)\n", result.r / 255,
			result.g / 255, result.b / 255);
	}
	free(sp);
	printf("\n");
}

void	pattern_test_battery(void)
{
	printf(BOLD_YELLOW "Patterns test battery\n" RESET);
	test_stripe_pattern(point(0, 0, 0), white(), "Stripe at (0, 0, 0)");
	test_stripe_pattern(point(0.9, 0, 0), white(), "Stripe at (0.9, 0, 0)");
	test_stripe_pattern(point(1, 0, 0), black(), "Stripe at (1, 0, 0)");
	test_stripe_pattern(point(-0.1, 0, 0), black(), "Stripe at (-0.1, 0, 0)");
	test_stripe_pattern(point(-1, 0, 0), black(), "Stripe at (-1, 0, 0)");
	test_stripe_pattern(point(-1.1, 0, 0), white(), "Stripe at (-1.1, 0, 0)");
	test_gradient_pattern(point(0, 0, 0), white(), "Gradient at (0, 0, 0)");
	test_gradient_pattern(point(0.25, 0, 0), color_scalarmult(0.75, white()),
		"Gradient at (0.25, 0, 0)");
	test_gradient_pattern(point(0.5, 0, 0), color_scalarmult(0.5, white()),
		"Gradient at (0.5, 0, 0)");
	test_gradient_pattern(point(0.75, 0, 0), color_scalarmult(0.25, white()),
		"Gradient at (0.75, 0, 0)");
	test_gradient_pattern(point(1, 0, 0), black(), "Gradient at (1, 0, 0)");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/08/2024 13:47:24 by hmorand           #+#    #+#             */
/*   Updated: 18/09/2024 10:05:39 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	tests(void)
{
	lighting_test_battery();
	ray_test_battery();
	hit_test_battery();
	pattern_test_battery();
}

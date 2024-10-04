/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_counter_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:44:28 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 10:44:29 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_count_bonus(t_file *file)
{
	count_identifier(&file->parse, file);
	if (file->count.a < 1 || \
		file->count.c < 1 || \
		file->count.l < 1)
		err_template(M_ACL_MISSING, NULL);
	if (file->count.a > 1)
		err_template(M_TOO_MANY_A, NULL);
	if (file->count.c > 1)
		err_template(M_TOO_MANY_C, NULL);
	if (file->count.r > 1)
		err_template(M_TOO_MANY_R, NULL);
}

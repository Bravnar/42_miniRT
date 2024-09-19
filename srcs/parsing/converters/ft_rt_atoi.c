/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:44:39 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 12:08:47 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	check_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	check_num(const char *str)
{
	int	dot_count;

	dot_count = 0;
	while (is_whitespace(*str))
		str++;
	while (*str && *str == '0' && *(str + 1) == '0')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '.')
			return (0);
		if (*str == '.')
			dot_count++;
		if (dot_count > 1)
			return (0);
		str++;
	}
	return (1);
}

int	ft_rt_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	while (is_whitespace(*nptr))
		nptr++;
	sign = check_sign(&nptr);
	if (!check_num(nptr))
		err_template(M_INVALID_ENTRY, (char *)nptr, NULL);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

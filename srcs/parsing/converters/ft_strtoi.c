/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:44:46 by smuravye          #+#    #+#             */
/*   Updated: 2024/09/19 10:44:47 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	toi_space_sign(const char **sptr, int *sign)
{
	while (ft_isspace(**sptr))
		(*sptr)++;
	if (ft_strchr("+-", **sptr))
	{
		if (**sptr == '-')
			*sign = -1;
		(*sptr)++;
	}
}

static int	final_decision(t_strtoi s, char **endptr, const char *nptr)
{
	if (s.digit_count == 0)
	{
		errno = EINVAL;
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	if (endptr)
		*endptr = (char *)s.s;
	return (s.sign * s.result);
}

int	ft_strtoi(const char *nptr, char **endptr)
{
	t_strtoi	strtoi;

	ft_bzero(&strtoi, sizeof(t_strtoi));
	strtoi.sign = 1;
	strtoi.s = nptr;
	toi_space_sign(&strtoi.s, &strtoi.sign);
	while (ft_isdigit(*strtoi.s))
	{
		strtoi.digit = *strtoi.s - '0';
		if (strtoi.result > INT_MAX / 10 || \
			(strtoi.result == INT_MAX / 10 && \
			strtoi.digit > INT_MAX % 10))
		{
			errno = ERANGE;
			if (endptr)
				*endptr = (char *)strtoi.s;
			if (strtoi.sign == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		strtoi.result = strtoi.result * 10 + strtoi.digit;
		strtoi.s++;
		strtoi.digit_count++;
	}
	return (final_decision(strtoi, endptr, nptr));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:05:57 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/20 17:06:22 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtoupper(char *str)
{
	int	i;

	i = -1;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
	}
	return (str);
}

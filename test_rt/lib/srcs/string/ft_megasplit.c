/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_megasplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:36:26 by smuravye          #+#    #+#             */
/*   Updated: 2024/04/06 14:42:46 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_strs(char *str, char *charset)
{
	int	i;
	int	elem_count;

	i = 0;
	elem_count = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i], charset))
			i++;
		if (str[i])
			elem_count++;
		while (str[i] && !is_in_charset(str[i], charset))
			i++;
	}
	return (elem_count);
}

static int	strlen_til_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_in_charset(str[i], charset))
	{
		i++;
	}
	return (i);
}

static char	*save_str(char *str, char *charset)
{
	int		str_len;
	int		i;
	char	*arr_word;

	i = 0;
	str_len = strlen_til_sep(str, charset);
	arr_word = malloc((str_len + 1) * sizeof(char));
	if (arr_word == NULL)
		return (NULL);
	while (i < str_len)
	{
		arr_word[i] = str[i];
		i++;
	}
	arr_word[i] = '\0';
	return (arr_word);
}

char	**ft_megasplit(char *str, char *charset)
{
	char	**breakdown;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	breakdown = malloc(sizeof(char *) * (count_strs(str, charset) + 1));
	if (breakdown == NULL)
		return (NULL);
	while (*str)
	{
		while (*str && is_in_charset(*str, charset))
			str++;
		if (*str)
		{
			breakdown[i] = save_str(str, charset);
			i++;
		}
		while (*str && !is_in_charset(*str, charset))
			str++;
	}
	breakdown[i] = 0;
	return (breakdown);
}

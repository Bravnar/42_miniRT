/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:14:09 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/07 10:16:07 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

static char	*malloc_word(char const *s, char c)
{
	size_t	word_length;
	size_t	i;
	char	*word;

	i = 0;
	word_length = word_len(s, c);
	word = malloc(sizeof(char) * (word_length + 1));
	if (!word)
		return (NULL);
	while (i < word_length)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char ***result, size_t words)
{
	size_t	count;
	size_t	i;

	count = -1;
	i = -1;
	while (words > ++count)
	{
		if ((*result)[count] == NULL)
		{
			while (words > ++i)
			{
				if ((*result)[i])
					free((*result)[i]);
			}
			free(*result);
			*result = NULL;
			return ;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split_arr;
	size_t	i;
	size_t	words;

	i = 0;
	words = count_words(s, c);
	if (s == NULL)
		return (NULL);
	split_arr = malloc(sizeof(char *) * (words + 1));
	if (!split_arr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			split_arr[i++] = malloc_word(s, c);
		}
		while (*s && *s != c)
			s++;
	}
	split_arr[i] = NULL;
	free_all(&split_arr, words);
	return (split_arr);
}

/* #include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	char	**new_arr;

	i = 0;
	if (ac < 2)
		return (0);
	new_arr = ft_split(av[1], 'z');
	while (new_arr[i])
	{
		printf("%s\n", new_arr[i]);
		i++;
	}
	free(new_arr);
	return (0);
}
 */

/* #include <stdio.h>

int 	main(void)
{
	char **words4 = ft_split("xxxxxxxxhello!", 'x');
	for (int l = 0; words4[l]; l++)
	{
		printf("%s$\n", words4[l]);
		free(words4[l]);
	}
	char **words6 = ft_split("--1-2--3---4----5-----42", '-');
	for (int n = 0; words6[n]; n++)
	{
		printf("%s$\n", words6[n]);
		free(words6[n]);
	}
}
 */